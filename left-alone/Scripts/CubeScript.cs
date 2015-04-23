using System.Collections;
using UnityEngine;

namespace Assets.Scripts
{
    public class CubeScript : MonoBehaviour
    {
        private int _blinkCounter = 4;
        private Transform _playerRootTransform;
        private bool _toggleKey;
        public float BlinkIntervals = 0.12f;
        public float FireProjectileSpeed = 40.0f;
        public float FireRate = 0.2f;
        public Collider2D LightAreaCollider2D;
        public DynamicLight TheLight;

        public void Start()
        {
            _playerRootTransform = transform.parent;
        }

        public void NotifyEnemyContact(EnemyBehaviour enemy)
        {
            ApplyBlink();
        }

        public void ApplyBlink()
        {
            _blinkCounter += 4;
            StartCoroutine(Blinking());
        }

        public IEnumerator Blinking()
        {
            while (_blinkCounter > 0)
            {
                LightAreaCollider2D.gameObject.SetActive(_toggleKey);
                TheLight.gameObject.SetActive(_toggleKey);

                _blinkCounter--;
                _toggleKey = !_toggleKey;
                yield return new WaitForSeconds(BlinkIntervals);
            }
        }
    }
}