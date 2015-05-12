using UnityEngine;

namespace Assets.Scripts
{
    public class BallController : MonoBehaviour
    {
        private bool _allowInput = true;
        private bool _positionNeedsUpdate = true;
        private float _targetY;
        private Transform _transform;
        public float DownTargetY;
        public bool GravitySwitch;
        public float MovementSpeed = 10f;
        public float UpTargetY;

        private void Start()
        {
            _targetY = DownTargetY;
            _positionNeedsUpdate = true;
            _transform = GetComponent<Transform>();
            GravitySwitch = true;
        }

        private void Update()
        {
            if (_allowInput)
            {
                if (Input.GetMouseButtonDown(0))
                {
                    ToggleGravity();
                }
            }
            if (_positionNeedsUpdate)
            {
                UpdatePosition();
            }
        }

        public void UpdatePosition()
        {
            _transform.position = new Vector3(_transform.position.x, Mathf.Lerp(_transform.position.y, _targetY, Time.deltaTime*MovementSpeed), _transform.position.z);

            if (Mathf.Abs(_transform.position.y - _targetY) < 0.5f)
            {
                _allowInput = true;
            }
            if (Mathf.Abs(_transform.position.y - _targetY) < 0.01f)
            {
                _positionNeedsUpdate = false;
            }
        }

        private void ToggleGravity()
        {
            _allowInput = false;
            if (GravitySwitch)
            {
                GravitySwitch = false;
                _targetY = UpTargetY;
            }

            else
            {
                GravitySwitch = true;
                _targetY = DownTargetY;
            }


            _positionNeedsUpdate = true;
        }
    }
}