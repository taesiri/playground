using UnityEngine;

namespace Assets.Scripts
{
    public class CollisionDetector : MonoBehaviour
    {
        public CubeScript PlayerCore;
        public Transform PlyaerTransform;

        public void OnTriggerEnter2D(Collider2D coll)
        {
            if (coll.gameObject.tag == "Enemy")
            {
                var helper = coll.GetComponent<EnemyColiderHelper>();
                helper.Notify(MessageType.LightEnter);
            }
        }

        public void OnTriggerStay2D(Collider2D coll)
        {
            if (coll.gameObject.tag == "Enemy")
            {
                var helper = coll.GetComponent<EnemyColiderHelper>();
                helper.Notify(MessageType.LightStay);
            }
        }

        public void OnTriggerExit2D(Collider2D coll)
        {
            if (coll.gameObject.tag == "Enemy")
            {
                var helper = coll.GetComponent<EnemyColiderHelper>();
                helper.Notify(MessageType.LightExit);
            }
        }
    }
}