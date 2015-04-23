using UnityEngine;

namespace Assets.Scripts
{
    public class EnemyColiderHelper : MonoBehaviour
    {
        public EnemyBehaviour Mother;

        public void Notify(MessageType typeOfMessage)
        {
            Mother.MessageReceived(typeOfMessage);
        }

        public void OnTriggerEnter2D(Collider2D coll)
        {
            if (coll.tag == "PlayerBody")
            {
                var cube = coll.GetComponent<CubeScript>();
                transform.parent.GetComponent<EnemyBehaviour>().NotifyContactWithPlayer(cube);
            }
        }
    }
}