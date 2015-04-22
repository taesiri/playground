using UnityEngine;

namespace Assets.Scripts
{
    public class GameCoreLogic : MonoBehaviour
    {
        public float FireRotationThreshold = 6.5f;
        public float RotationSpeed = 10.0f;
        public CubeScript TheCube;

        private void Start()
        {
            if (TheCube == null)
            {
                Debug.LogError("Cube is missing!");
            }
        }

        private void Update()
        {
            if (Input.GetMouseButton(0))
            {
                var pos = Camera.main.ScreenToWorldPoint(Input.mousePosition);


                var targetZ = Mathf.Atan2(pos.y, pos.x)*180/Mathf.PI - 90f;

                var delta = Mathf.Abs(TheCube.transform.eulerAngles.z - targetZ);
                if (delta > 350)
                    delta = Mathf.Abs(delta - 360);

                if (delta > FireRotationThreshold)
                {
                    TheCube.transform.eulerAngles = new Vector3(0, 0, Mathf.LerpAngle(TheCube.transform.eulerAngles.z, targetZ, Time.deltaTime*RotationSpeed));
                }
                else
                {
                    ReadyToFire(pos, targetZ);
                }
            }
        }

        public void ReadyToFire(Vector3 pos, float zTarget)
        {
        }
    }
}