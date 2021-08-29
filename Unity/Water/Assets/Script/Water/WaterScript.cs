using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaterScript : MonoBehaviour
{
	// A = -K/M * X

	public MeshFilter meshFilter;

	public int columnCount = 10; // columns�� ��
	public float width = 2f; // ���� ũ��
	public float height = 1f; // ���� ũ��
	public float k = 0.025f; // ���� ������
	public float m = 1;	// ����
	public float drag = 0.025f; // ���� ����
	public float spread = 0.025f; // ���� ������ ��
	public float power = -1f; // ��

	private List<WaterColumn> columns = new List<WaterColumn>();
	private void Start()
	{
		Setup();
	}

	private void Setup()
	{
		columns.Clear();
		float space = width / columnCount;
		for (int i = 0; i < columnCount + 1; i++)
		{
			columns.Add(new WaterColumn(i * space - width * 0.5f, height, k, m, drag));
		}
	}

	internal int? WorldToColumn(Vector2 position)
	{
		float space = width / columnCount;
		int result = Mathf.RoundToInt((position.x + width * 0.5f) / space);
		if (result >= columns.Count || result < 0)
			return null;
		return result;
	}

	private void Update()
	{
		// ���콺 Ŭ�� ���� �� ���콺�� ��ġ�� ���ֱ�
		int? column = WorldToColumn(Camera.main.ScreenToWorldPoint(Input.mousePosition));
		if (Input.GetMouseButton(0) && column.HasValue)
			columns[column.Value].velocity = power;
	}

	private void FixedUpdate()
	{
		for (int i = 0; i < columns.Count; i++) // ���� ���
		{
			columns[i].UpdateColumn();
		}

		float[] leftDeltas = new float[columns.Count];
		float[] rightDeltas = new float[columns.Count];
		for (int i = 0; i < columns.Count; i++)
		{
			if (i > 0)
			{
				leftDeltas[i] = (columns[i].height - columns[i - 1].height) * spread;
				columns[i - 1].velocity += leftDeltas[i];
			}
			if (i < columns.Count - 1)
			{
				rightDeltas[i] = (columns[i].height - columns[i + 1].height) * spread;
				columns[i + 1].velocity += rightDeltas[i];
			}
		}
		for (int i = 0; i < columns.Count; i++)
		{
			if (i > 0)
			{
				columns[i - 1].height += leftDeltas[i];
			}
			if (i < columns.Count - 1)
			{
				columns[i + 1].height += rightDeltas[i];
			}
		}


		Mesh mesh = new Mesh();
		Vector3[] vertices = new Vector3[columns.Count * 2];
		int v = 0;
		for (int i = 0; i < columns.Count; i++)
		{
			vertices[v] = new Vector2(columns[i].xPos, columns[i].height);
			vertices[v + 1] = new Vector2(columns[i].xPos, 0f);

			v += 2;
		}

		int[] triangles = new int[(columns.Count - 1) * 6];
		int t = 0;
		v = 0;
		for (int i = 0; i < columns.Count - 1; i++)
		{
			triangles[t] = v;
			triangles[t + 1] = v + 2;
			triangles[t + 2] = v + 1;
			triangles[t + 3] = v + 1;
			triangles[t + 4] = v + 2;
			triangles[t + 5] = v + 3;

			v += 2;
			t += 6;
		}

		mesh.vertices = vertices;
		mesh.triangles = triangles;

		mesh.RecalculateNormals();
		mesh.RecalculateBounds();
		mesh.Optimize();

		meshFilter.mesh = mesh;
	}


}
