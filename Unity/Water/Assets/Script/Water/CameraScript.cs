using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraScript : MonoBehaviour
{
    private void Update()
    {
        Camera.main.orthographicSize += Input.GetAxis("Mouse ScrollWheel") * 5;
    }
}
