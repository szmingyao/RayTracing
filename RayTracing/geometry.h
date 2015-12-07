﻿//
		// data
		union
		{
			struct
			{
				double xMin, yMin, zMin, xMax, yMax, zMax;
			};
			struct
			{
				Vec3d minvec, maxvec;
			};
		};
			xMax = yMax = zMax = -DBL_MAX;
		{
			double xsize = xMax - xMin;
			double ysize = yMax - yMin;
			double zsize = zMax - zMin;
			if (xsize > ysize)
			{
				if (xsize > zsize)
					return 0;
				else
					return 2;
			}
			else
			{
				if (ysize > zsize)
					return 1;
				else
					return 2;
			}
		}
		// union another BBox box with this BBox
		inline void Union(const BBox & box)
		{
			xMin = Min(box.xMin, xMin);
			yMin = Min(box.yMin, yMin);
			zMin = Min(box.zMin, zMin);

			xMax = Max(box.xMax, xMax);
			yMax = Max(box.yMax, yMax);
			zMax = Max(box.zMax, zMax);
		}
		// union another point3d or vec3d
		inline void Union(const Vec3d &v)
		{
			xMin = Min(v(0), xMin);
			yMin = Min(v(1), yMin);
			zMin = Min(v(2), zMin);

			xMax = Max(v(0), xMax);
			yMax = Max(v(1), yMax);
			zMax = Max(v(2), zMax);
		}
	};

	/*inline void TransformBBox(BBox & bboxOut, const Matrix4d & mat, const BBox & bboxIn)
	{
		Vec3d v, v_t;
		bboxOut.Init();
		for (int i = 0; i < 8; i++)
		{
			if (i & 1)
				v(0) = bboxIn.xMax;
			else
				v(0) = bboxIn.xMin;
			if (i & 2)
				v(1) = bboxIn.yMax;
			else
				v(1) = bboxIn.yMin;
			if (i & 4)
				v(2) = bboxIn.zMax;
			else
				v(2) = bboxIn.zMin;
			mat.Transform(v_t, v);
			bboxOut.Union(v_t);
		}