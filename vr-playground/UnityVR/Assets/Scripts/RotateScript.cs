using UnityEngine;

namespace Assets.Scripts
{
    public class RotateScript : MonoBehaviour
    {
        private Transform _transform;
        public Vector3 RotateionAxis = Vector3.zero;
        public float RotationSpeed = 25f;
        private void Start()
        {
            _transform = transform;
        }

        private void Update()
        {
            _transform.RotateAround(_transform.position, RotateionAxis, Time.deltaTime*RotationSpeed);
        }
    }
}