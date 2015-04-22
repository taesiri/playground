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
    }
}