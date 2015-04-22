using UnityEngine;

namespace Assets.Scripts
{
    public class EnemyBehaviour : MonoBehaviour
    {
        private Transform _targetTransform;
        public EnemyState State;
        public CubeScript TargetCube;



        public void Start()
        {
            UpdateTarget();
        }

        public void UpdateTarget(CubeScript cScript)
        {
            TargetCube = cScript;
            _targetTransform = TargetCube.transform;
        }

        public void UpdateTarget()
        {
            _targetTransform = TargetCube.transform;
        }

        public void MessageReceived(MessageType typeOfMessage)
        {
        }

        public void Update()
        {
            switch (State)
            {
                case EnemyState.Idle:
                    break;

                case EnemyState.Attack:
                    break;

                case EnemyState.RunningAway:
                    break;
            }
        }

        public void UpdateLocation()
        {

        }
    }
}