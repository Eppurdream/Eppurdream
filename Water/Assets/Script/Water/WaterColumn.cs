using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaterColumn
{
	public float xPos, height, targetHeight, k, m, velocity, drag;

	public WaterColumn(float xPos, float targetHeight, float k, float m, float drag)
	{
		this.xPos = xPos;
		this.height = targetHeight;
		this.targetHeight = targetHeight;
		this.k = k;
		this.m = m;
		this.drag = drag;
	}

	public void UpdateColumn()
	{
		float a = -k / m * (height - targetHeight);
		velocity += a;
		velocity -= drag * velocity;
		height += velocity;
	}
}
