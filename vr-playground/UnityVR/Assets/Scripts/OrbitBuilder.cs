using UnityEngine;

namespace Assets.Scripts
{
    public class OrbitBuilder : MonoBehaviour
    {
        public GameObject BlockPrefab;
        public int NumberOfCubes = 4;
        public int NumberOfLevels;
        public float Range = 100f;
        public float SpaceBetweenEachLevel = 20f;
    }
}