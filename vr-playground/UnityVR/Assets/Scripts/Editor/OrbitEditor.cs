using System;
using UnityEditor;
using UnityEngine;
using Random = System.Random;

namespace Assets.Scripts.Editor
{
    [CustomEditor(typeof (OrbitBuilder))]
    public class OrbitEditor : UnityEditor.Editor
    {
        public static Random RndGenerator = new Random(DateTime.Now.Millisecond);

        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();
            var grid = (OrbitBuilder) target;


            if (GUILayout.Button("Build!"))
            {
                UpdateGridSize(grid);
            }
        }

        private void UpdateGridSize(OrbitBuilder builder)
        {
            if (builder.BlockPrefab != null)
            {
                var transform = builder.transform;

                for (var k = 0; k < builder.NumberOfLevels; k++)
                {
                    var core = new GameObject(name = " Core ");
                    core.transform.position = new Vector3(0, k*builder.SpaceBetweenEachLevel, 0);
                    var coreRotater = core.AddComponent<RotateScript>();
                    coreRotater.RotateionAxis = Vector3.up;
                    coreRotater.RotationSpeed = RndGenerator.Next(1, 10)*10;


                    for (var i = 0; i < builder.NumberOfCubes; i++)
                    {
                        var deltaZ = Mathf.Sin(360*i/(float) builder.NumberOfCubes*(Mathf.PI/180))*builder.Range;
                        var deltaX = Mathf.Cos(360*i/(float) builder.NumberOfCubes*(Mathf.PI/180))*builder.Range;


                        var newCube =
                            (GameObject)
                                Instantiate(builder.BlockPrefab, transform.position + new Vector3(deltaX, core.transform.position.y, deltaZ),
                                    Quaternion.identity);

                        newCube.transform.parent = core.transform;
                    }


                    core.transform.parent = builder.transform;
                }
            }
            else
            {
                Debug.LogError("Block Prefab is Empty!");
            }
        }
    }
}