# include "Collision.hpp"

# include "../Transform/Vector3.hpp"

# include "../Utility/Optional.hpp"
# include "../Utility/Math.hpp"
# include "../Utility/Range.hpp"

# include "../Shapes/Sphere.hpp"
# include "../Shapes/Capsule.hpp"
# include "../Shapes/Segment.hpp"
# include "../Shapes/Mesh.hpp"

namespace Aquaworks
{
	namespace Physics
	{
		namespace Collision
		{
			using namespace Transform;
			using namespace Utility;
			using namespace Shapes;

			bool SphereSphere(Vector3 const& center1, float radius1, Vector3 const& center2, float radius2)
			{
				float r = radius1 + radius2;
				return Vector3::LengthSquared((center2 - center1)) <= r * r;
			}

			bool SpherePlane(Vector3 const& center, float radius, Vector3 const& normal, float distance)
			{
				// ���_���畽�ʂ܂ł̃x�N�g��
				Vector3 pn = normal * distance;

				// ���ʂ��狅�܂ł̃x�N�g��
				Vector3 c = center - pn;

				// ����
				float l = Vector3::Dot(c, normal);

				// ���������a��蒷����ΏՓ˂��Ă��Ȃ�
				if (l > radius)
				{
					return false;
				}

				return true;
			}

			bool SphereSegment(Vector3 const& center, float radius, Vector3 const& begin, Vector3 const& end)
			{
				// �����̃x�N�g��
				Vector3 v = end - begin;
				// ������n�_�܂ł̃x�N�g��
				Vector3 v1 = center - begin;

				// ������n�_�܂ł̃x�N�g���������̃x�N�g���ɉe�����y�ڂ�����
				float t = Vector3::Dot(v, v1) / Vector3::Dot(v, v);

				// �ŋߓ_
				Vector3 p =
					t < 0.0f ? begin :
					1.0f < t ? end :
					begin + v * t;

				// ���������a��蒷����ΏՓ˂��Ă��Ȃ�
				if (Vector3::LengthSquared(center - p) >= radius * radius)
				{
					return false;
				}

				return true;
			}

			bool SegmentPlane(Vector3 const& begin, Vector3 const& end, Vector3 const& normal, float distance)
			{
				Optional<float> t = RatioSegmentPlane(begin, end, normal, distance);

				if (!t || Range<float>(0.0f, 1.0f).IsExcluded(*t))
				{
					return false;
				}

				return true;
			}

			bool SegmentSegment(Vector3 const& begin1, Vector3 const& end1, Vector3 const& begin2, Vector3 const& end2, float distance)
			{
				// ���̕ύX
				Vector3 const& p1 = begin1;
				Vector3 const& p2 = end1;
				Vector3 const& p3 = begin2;
				Vector3 const& p4 = end2;

				// �x�N�g��
				Vector3 const a = p2 - p1;
				Vector3 const b = p4 - p3;
				Vector3 const c = p3 - p1;
				Vector3 n = Vector3::Cross(a, b);

				// �@���̒�����0�Ȃ�ڐG�Ȃ�
				if (Vector3::LengthSquared(n) == 0.0f)
				{
					return false;
				}

				n = Vector3::Normalize(n);

				// ����
				float d = Vector3::Dot(c, n);

				if (Math::Abs(d) > distance)
				{
					return false;
				}

				Vector3 const v1 = p1 - p3;
				Vector3 const v2 = p2 - p3;
				Vector3 const v3 = p3 - p1;
				Vector3 const v4 = p4 - p2;

				float l1 = Vector3::Dot(n, v1);
				float l2 = Vector3::Dot(n, v2);
				float l3 = Vector3::Dot(n, v3);
				float l4 = Vector3::Dot(n, v4);

				float t1 = l1 / (l1 - l2);
				float t2 = l3 / (l3 - l4);

				Range<float> const range { 0.0f, 1.0f };

				if (range.IsExcluded(t1) || range.IsExcluded(t2))
				{
					return false;
				}

				return true;
			}

			bool CapsuleCapsule(Vector3 const& begin1, Vector3 const& end1, float radius1, Vector3 const& begin2, Vector3 const& end2, float radius2)
			{
				// ���̕ύX
				Vector3 const& p1 = begin1;
				Vector3 const& p2 = end1;
				Vector3 const& p3 = begin2;
				Vector3 const& p4 = end2;

				// �x�N�g��
				Vector3 const a = p2 - p1;
				Vector3 const b = p4 - p3;
				Vector3 const c = p3 - p1;
				Vector3 n = Vector3::Cross(a, b);

				// �@���̒�����0�Ȃ�ڐG�Ȃ�
				if (Vector3::LengthSquared(n) == 0.0f)
				{
					return false;
				}

				n = Vector3::Normalize(n);

				// ���a�̍��v
				float radius = radius1 + radius2;

				// ����
				float d = Vector3::Dot(c, n);

				if (Math::Abs(d) > radius * radius)
				{
					return false;
				}

				// ��ڂ̐����̕��ʂɎˉe�����[�_
				Vector3 const P3 = p3 - n * d;
				Vector3 const P4 = p4 - n * d;

				// �[�_�̖@��
				Vector3 const n1 = Vector3::Normalize(Vector3::Cross(n, a));
				Vector3 const n2 = Vector3::Normalize(Vector3::Cross(n, b));

				Vector3 const v1 = p1 - P3;
				Vector3 const v2 = p2 - P3;
				Vector3 const v3 = P3 - p1;
				Vector3 const v4 = P4 - p2;

				float l1 = Vector3::Dot(n2, v1);
				float l2 = Vector3::Dot(n2, v2);
				float l3 = Vector3::Dot(n1, v3);
				float l4 = Vector3::Dot(n2, v4);

				float t1 = l1 / (l1 - l2);
				float t2 = l3 / (l3 - l4);

				Range<float> const range { 0.0f, 1.0f };

				if (range.IsExcluded(t1) || range.IsExcluded(t2))
				{
					return false;
				}

				return true;
			}

			bool CapsulePlane(Vector3 const& begin, Vector3 const& end, float radius, Vector3 const& normal, float distance)
			{
				// ���ʏ�̂P�_
				Vector3 const p0 = normal * distance;

				// ���O�̕ύX
				Vector3 const& p1 = begin;
				Vector3 const& p2 = end;

				// �P�_����[�_�܂ł̃x�N�g��
				Vector3 const v1 = p1 - p0;
				Vector3 const v2 = p2 - p0;

				// �@���ƃx�N�g���̓��ςŕ��ʂ���[�_�܂ł̋��������߂�
				float l1 = Vector3::Dot(normal, v1);
				float l2 = Vector3::Dot(normal, v2);

				// �n�_���ŐڐG���Ă���ꍇ
				if (l1 < radius)
				{
					// �n�_�𒆐S�Ƃ������ƕ��ʂ̏Փ˔�����s�Ȃ�
					return SpherePlane(p1, radius, normal, distance);
				}
				// �I�_���ŐڐG���Ă���ꍇ
				if (l2 < radius)
				{
					// �I�_�𒆐S�Ƃ������ƕ��ʂ̏Փ˔�����s�Ȃ�
					return SpherePlane(p2, radius, normal, distance);
				}

				return false;
			}

			Optional<float> RatioSegmentPlane(Vector3 const& begin, Vector3 const& end, Vector3 const& normal, float distance)
			{
				// ���ʏ�̂P�_
				Vector3 p0 = normal * distance;

				// �P�_����n�_�܂ł̃x�N�g��
				Vector3 v1 = begin - p0;
				// �P�_����I�_�܂ł̃x�N�g��
				Vector3 v2 = end - p0;

				// �@���ƃx�N�g���̓��ςŁA���ʂ���[�_�܂ł̋��������߂�
				float l1 = Vector3::Dot(normal, v1);
				float l2 = Vector3::Dot(normal, v2);

				// l1��l2����������Ε��s�Ȃ��ߌ�_�����݂��Ȃ�
				if (l1 == l2)
				{
					return NullOpt::None;
				}

				// ������𕽖ʂ܂ł̋����̔䗦��p���ċ��߂�
				return l1 / (l1 - l2);
			}

			bool PolygonInside(std::vector<Vector3> const& vertices, Vector3 const& point)
			{
				// �x�N�g��
				Vector3 v1 = vertices[1] - vertices[0];
				Vector3 v2 = point - vertices[0];

				// �@��
				Vector3 n = Vector3::Cross(v1, v2);

				for (std::vector<Vector3>::size_type i = 0; i < vertices.size(); ++i)
				{
					v1 = vertices[(i + 1) % vertices.size()] - vertices[i];
					v2 = point - vertices[i];

					if (Vector3::Dot(n, Vector3::Cross(v1, v2)) < 0.0f)
					{
						return false;
					}
				}

				return true;
			}

			bool SphereSphere(Sphere const& sphere1, Sphere const& sphere2)
			{
				return SphereSphere(
					sphere1.origin.position, sphere1.radius,
					sphere2.origin.position, sphere2.radius);
			}

			bool SphereCapsule(Sphere const& sphere, Capsule const& capsule)
			{
				return SphereSegment(
					sphere.origin.position, sphere.radius + capsule.radius,
					capsule.begin * capsule.origin, capsule.end * capsule.origin);
			}

			bool SphereSegment(Sphere const& sphere, Segment const& segment)
			{
				return SphereSegment(
					sphere.origin.position, sphere.radius,
					segment.begin * segment.origin, segment.end * segment.origin);
			}

			bool SphereMesh(Sphere const& sphere, Mesh const& mesh)
			{
				if (!SphereSphere(sphere, *(Sphere*)mesh.BoundingSphere().get()))
				{
					return false;
				}

				Mesh::VertexBuffer const& vertices = mesh.vertices;
				Mesh::IndexBuffer const& indices = mesh.indices;

				Vector3 p0 = sphere.origin.position;

				for (size_t i = 0; i < indices.size(); i += 3)
				{
					Vector3 p1 = vertices.at(indices.at(i)).position;
					Vector3 p2 = vertices.at(indices.at(i + 1)).position;
					Vector3 p3 = vertices.at(indices.at(i + 2)).position;
					p1 *= mesh.origin;
					p2 *= mesh.origin;
					p3 *= mesh.origin;

					Vector3 a = p2 - p1;
					Vector3 b = p3 - p1;
					Vector3 c = p1 - p0;
					Vector3 n = Vector3::Normalize(Vector3::Cross(a, b));
					float length = Vector3::Dot(c, n);
					if (Math::Abs(length) > sphere.radius * sphere.origin.scaling.x)
					{
						continue;
					}
					Vector3 point = p0 + n * length;

					if (PolygonInside({ p1, p2, p3 }, point))
					{
						return true;
					}
				}

				return false;
			}

			bool CapsuleCapsule(Capsule const& capsule1, Capsule const& capsule2)
			{
				return CapsuleCapsule(
					capsule1.begin * capsule1.origin, capsule1.end * capsule1.origin, capsule1.radius,
					capsule2.begin * capsule2.origin, capsule2.end * capsule2.origin, capsule2.radius);
			}

			bool CapsuleSegment(Capsule const& capsule, Segment const& segment)
			{
				return CapsuleCapsule(
					capsule.begin * capsule.origin, capsule.end * capsule.origin, capsule.radius,
					segment.begin * segment.origin, segment.end * segment.origin, 0.0f);
			}

			bool CapsuleMesh(Capsule const& capsule, Mesh const& mesh)
			{
				if (!SphereCapsule(*(Sphere*)mesh.BoundingSphere().get(), capsule))
				{
					return false;
				}

				Mesh::VertexBuffer const& vertices = mesh.vertices;
				Mesh::IndexBuffer const& indices = mesh.indices;

				Vector3 begin = capsule.begin * capsule.origin;
				Vector3 end = capsule.end * capsule.origin;
				float radius = capsule.radius;

				for (size_t i = 0; i < indices.size(); i += 3)
				{
					Vector3 p1 = vertices.at(indices.at(i)).position * mesh.origin;
					Vector3 p2 = vertices.at(indices.at(i + 1)).position * mesh.origin;
					Vector3 p3 = vertices.at(indices.at(i + 2)).position * mesh.origin;

					Mesh::PositionBuffer polygon = { p1, p2, p3 };

					Vector3 a = p2 - p1;
					Vector3 b = p3 - p1;

					Vector3 n = Vector3::Cross(a, b);
					float distance = Vector3::Dot(n, p1);
					Vector3 p0 = n * distance;

					Vector3 v = end - begin;
					Vector3 v1 = begin - p0;
					Vector3 v2 = end - p0;

					float l1 = Vector3::Dot(n, v1);
					float l2 = Vector3::Dot(n, v2);

					bool isPolygonInside = false;

					// �J�v�Z���ƃ|���S�������s�łȂ���
					if (l1 - l2 != 0)
					{
						float t = l1 / (l1 - l2);
						// ��_
						isPolygonInside = PolygonInside(polygon, begin + v * t);
					}
					else
					{
						isPolygonInside = PolygonInside(polygon, begin) || PolygonInside(polygon, end);
					}

					// �|���S�����ɑ��݂���ꍇ
					if (isPolygonInside)
					{
						if (l1 < radius)
						{
							Vector3 p = begin;
							// �[�_���S�̋��ƕ��ʂ̏Փ˔���
							if (SpherePlane(p, radius, n, distance))
							{
								return true;
							}
						}
						if (l2 < radius)
						{
							Vector3 p = end;
							// �[�_���S�̋��ƕ��ʂ̏Փ˔���
							if (SpherePlane(p, radius, n, distance))
							{
								return true;
							}
						}
					}
					// �[�_���O���ɂ���ꍇ�����ƃJ�v�Z���ŏՓ˔���
					else
					{
						SegmentSegment(p1, p2, begin, end, radius);
						SegmentSegment(p2, p3, begin, end, radius);
						SegmentSegment(p3, p1, begin, end, radius);

						size_t polygonSize = polygon.size();
						for (size_t j = 0; j < polygonSize; ++j)
						{
							size_t k = (j + 1) % polygonSize;
							if (CapsuleCapsule(
								polygon[j], polygon[k], 0.0f,
								begin, end, radius))
							{
								return true;
							}

						}
					}
				}

				return false;
			}

			bool SegmentSegment(Segment const& segment1, Segment const& segment2)
			{
				Vector3 begin1 = segment1.begin;
				Vector3 end1 = segment1.end;
				Vector3 begin2 = segment2.begin;
				Vector3 end2 = segment2.end;

				Vector3 a = end1 - begin1;
				Vector3 b = end2 - begin2;
				Vector3 c = begin2 - begin1;
				Vector3 n = Vector3::Normalize(Vector3::Cross(a, b));
				float length = Vector3::Dot(n, c);
				return Math::Abs(length) < Math::Eps;
			}

			bool SegmentMesh(Segment const& segment, Mesh const& mesh)
			{
				if (!SphereSegment(*(Sphere*)mesh.BoundingSphere().get(), segment))
				{
					return false;
				}

				Mesh::VertexBuffer const& vertices = mesh.vertices;
				Mesh::IndexBuffer const& indices = mesh.indices;

				Vector3 const begin = segment.begin * segment.origin;
				Vector3 const end = segment.end * segment.origin;

				for (size_t i = 0; i < indices.size(); i += 3)
				{
					Vector3 const& p1 = vertices.at(indices.at(i)).position * mesh.origin;
					Vector3 const& p2 = vertices.at(indices.at(i + 1)).position * mesh.origin;
					Vector3 const& p3 = vertices.at(indices.at(i + 2)).position * mesh.origin;

					Vector3 const a = p2 - p1;
					Vector3 const b = p3 - p1;
					Vector3 const n = Vector3::Normalize(Vector3::Cross(a, b));

					Vector3 const p0 = n * Vector3::Dot(n, p1);

					Vector3 const v1 = begin - p0;
					Vector3 const v2 = end - p0;

					float l1 = Vector3::Dot(n, v1);
					float l2 = Vector3::Dot(n, v2);

					// ���s�łȂ���
					if (l1 - l2 != 0)
					{
						float t = l1 / (l1 - l2);
						if (Range<float>(0.0f, 1.0f).IsExcluded(t))
						{
							continue;
						}
						if (PolygonInside({ p1, p2, p3 }, begin + (end - begin) * t))
						{
							return true;
						}
					}
				}

				return false;
			}

			bool MeshMesh(Mesh const& mesh1, Mesh const& mesh2)
			{
				if (!SphereSphere(
					*(Sphere*)mesh1.BoundingSphere().get(),
					*(Sphere*)mesh2.BoundingSphere().get()))
				{
					return false;
				}

				return true;

				// return false;
			}
		}
	}
}
