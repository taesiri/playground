using UnityEngine;

namespace Assets.Scripts
{
    public class EnemyBehaviour : MonoBehaviour
    {
        private Rigidbody2D _rigidbody2D;
        private Transform _transform;
        public bool InLight;
        public float RotationSpeed = 6.0f;
        public float Speed;
        public EnemyState State;
        public CubeScript TargetCube;
        public Transform TargetTransform;

        public void Start()
        {
            UpdateTarget();

            _rigidbody2D = GetComponent<Rigidbody2D>();

            _transform = GetComponent<Transform>();
        }

        public void UpdateTarget(CubeScript cScript, Transform tragetTransform)
        {
            TargetCube = cScript;
            TargetTransform = tragetTransform;
        }

        public void UpdateTarget()
        {
            TargetTransform = TargetCube.transform;
        }

        public void MessageReceived(MessageType typeOfMessage)
        {
            switch (typeOfMessage)
            {
                case MessageType.LightEnter:
                    InLight = true;
                    break;

                case MessageType.LightStay:
                    break;


                case MessageType.LightExit:
                    InLight = false;
                    break;
            }
        }

        public void Update()
        {
            switch (State)
            {
                case EnemyState.Idle:
                    HandleIdle();
                    break;

                case EnemyState.Attack:
                    HandleAttack();
                    break;

                case EnemyState.RunningAway:
                    HandleRunningAway();
                    break;
            }
        }

        public void ApplyMovement(Vector3 direction)
        {
            if (InLight)
            {
                direction += new Vector3(direction.y, -direction.x, 0);

                Debug.DrawLine(transform.position, direction, Color.red);

                _rigidbody2D.AddForce((direction)*Speed, ForceMode2D.Impulse);
                _rigidbody2D.velocity = _rigidbody2D.velocity.normalized*Speed;
            }
            else
            {
                _rigidbody2D.AddForce((direction)*Speed, ForceMode2D.Impulse);
                _rigidbody2D.velocity = _rigidbody2D.velocity.normalized*Speed;
            }


            var targetZ = Mathf.Atan2(_rigidbody2D.velocity.y, _rigidbody2D.velocity.x)*180/Mathf.PI - 90f;
            _transform.eulerAngles = new Vector3(0, 0, Mathf.LerpAngle(_transform.eulerAngles.z, targetZ, Time.deltaTime*RotationSpeed));
        }

        public void HandleIdle()
        {
            _rigidbody2D.velocity = Vector2.zero;
        }

        public void HandleAttack()
        {
            var direction = TargetTransform.position - _transform.position;
            ApplyMovement(direction);
        }

        public void HandleRunningAway()
        {
            var direction = _transform.position - TargetTransform.position;
            ApplyMovement(direction);
        }

        public void NotifyContactWithPlayer(CubeScript playerScript)
        {
            playerScript.NotifyEnemyContact(this);


            gameObject.SetActive(false);
        }
    }
}