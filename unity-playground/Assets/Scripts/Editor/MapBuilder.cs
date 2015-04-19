using UnityEditor;
using UnityEngine;

namespace Assets.Scripts.Editor
{
    [CustomEditor(typeof (WorldMap))]
    public class MapBuilder : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();

            if (GUILayout.Button("Draw Map"))
            {
                CreateGrid();
            }

            if (GUILayout.Button("Clear Map"))
            {
                DeleteChildern();
            }
        }

        private void CreateGrid()
        {
            var grid = (WorldMap) target;
            grid.Tiles = new TileBehaviour[grid.Width, grid.Height, grid.Depth];

            for (var i = 0; i < grid.Width; i++)
            {
                for (var j = 0; j < grid.Height; j++)
                {
                    for (var k = 0; k < grid.Depth; k++)
                    {
                        var newDot = (GameObject)Instantiate(grid.WorldTilePrefab, new Vector3(-2.4f + i * grid.GridSize, -4.21f + j * grid.GridSize, k * grid.GridSize), Quaternion.identity);


                        newDot.transform.parent = grid.transform;

                        var tileScript = newDot.GetComponent<TileBehaviour>();
                        tileScript.WorldOffset = new Vector3(i, j, k);


                        grid.Tiles[i, j, k] = tileScript;
                    }
                }
            }
        }

        private void DeleteChildern()
        {
            var grid = (WorldMap) target;
            var childs = new Transform[grid.transform.childCount];

            for (var i = 0; i < grid.transform.childCount; i++)
            {
                childs[i] = grid.transform.GetChild(i);
            }
            for (var i = 0; i < childs.Length; i++)
            {
                DestroyImmediate(childs[i].gameObject);
            }
        }
    }
}