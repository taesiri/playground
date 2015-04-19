using UnityEngine;

namespace Assets.Scripts
{
    public class WorldMap : MonoBehaviour
    {
        public int Depth;
        public int Height;
        public TileBehaviour[,,] Tiles;
        public int Width;
        public GameObject WorldTilePrefab;

        public float GridSize = 1.01f;
    }
}