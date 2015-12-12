# include "Collision.hpp"

# include "Transform/Vector3.hpp"

# include "Utility/Optional.hpp"
# include "Utility/Math.hpp"
# include "Utility/Range.hpp"

namespace Physics
{
	namespace Collision
	{
		using namespace Transform;
		using namespace Utility;

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
			Vector3 v1 = center - end;

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
	}
}
