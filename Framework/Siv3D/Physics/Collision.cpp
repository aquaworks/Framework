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
			// 原点から平面までのベクトル
			Vector3 pn = normal * distance;

			// 平面から球までのベクトル
			Vector3 c = center - pn;

			// 距離
			float l = Vector3::Dot(c, normal);

			// 距離が半径より長ければ衝突していない
			if (l > radius)
			{
				return false;
			}

			return true;
		}

		bool SphereSegment(Vector3 const& center, float radius, Vector3 const& begin, Vector3 const& end)
		{
			// 線分のベクトル
			Vector3 v = end - begin;
			// 球から始点までのベクトル
			Vector3 v1 = center - end;

			// 球から始点までのベクトルが線分のベクトルに影響を及ぼす割合
			float t = Vector3::Dot(v, v1) / Vector3::Dot(v, v);

			// 最近点
			Vector3 p =
				t < 0.0f ? begin :
				1.0f < t ? end :
				begin + v * t;

			// 距離が半径より長ければ衝突していない
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
			// 名称変更
			Vector3 const& p1 = begin1;
			Vector3 const& p2 = end1;
			Vector3 const& p3 = begin2;
			Vector3 const& p4 = end2;

			// ベクトル
			Vector3 const a = p2 - p1;
			Vector3 const b = p4 - p3;
			Vector3 const c = p3 - p1;
			Vector3 n = Vector3::Cross(a, b);

			// 法線の長さが0なら接触なし
			if (Vector3::LengthSquared(n) == 0.0f)
			{
				return false;
			}

			n = Vector3::Normalize(n);

			// 距離
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
			// 名称変更
			Vector3 const& p1 = begin1;
			Vector3 const& p2 = end1;
			Vector3 const& p3 = begin2;
			Vector3 const& p4 = end2;

			// ベクトル
			Vector3 const a = p2 - p1;
			Vector3 const b = p4 - p3;
			Vector3 const c = p3 - p1;
			Vector3 n = Vector3::Cross(a, b);

			// 法線の長さが0なら接触なし
			if (Vector3::LengthSquared(n) == 0.0f)
			{
				return false;
			}

			n = Vector3::Normalize(n);

			// 半径の合計
			float radius = radius1 + radius2;

			// 距離
			float d = Vector3::Dot(c, n);

			if (Math::Abs(d) > radius * radius)
			{
				return false;
			}

			// 一つ目の線分の平面に射影した端点
			Vector3 const P3 = p3 - n * d;
			Vector3 const P4 = p4 - n * d;

			// 端点の法線
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
			// 平面上の１点
			Vector3 const p0 = normal * distance;

			// 名前の変更
			Vector3 const& p1 = begin;
			Vector3 const& p2 = end;

			// １点から端点までのベクトル
			Vector3 const v1 = p1 - p0;
			Vector3 const v2 = p2 - p0;

			// 法線とベクトルの内積で平面から端点までの距離を求める
			float l1 = Vector3::Dot(normal, v1);
			float l2 = Vector3::Dot(normal, v2);

			// 始点側で接触している場合
			if (l1 < radius)
			{
				// 始点を中心とした球と平面の衝突判定を行なう
				return SpherePlane(p1, radius, normal, distance);
			}
			// 終点側で接触している場合
			if (l2 < radius)
			{
				// 終点を中心とした球と平面の衝突判定を行なう
				return SpherePlane(p2, radius, normal, distance);
			}

			return false;
		}

		Optional<float> RatioSegmentPlane(Vector3 const& begin, Vector3 const& end, Vector3 const& normal, float distance)
		{
			// 平面上の１点
			Vector3 p0 = normal * distance;

			// １点から始点までのベクトル
			Vector3 v1 = begin - p0;
			// １点から終点までのベクトル
			Vector3 v2 = end - p0;

			// 法線とベクトルの内積で、平面から端点までの距離を求める
			float l1 = Vector3::Dot(normal, v1);
			float l2 = Vector3::Dot(normal, v2);

			// l1とl2が等しければ平行なため交点が存在しない
			if (l1 == l2)
			{
				return NullOpt::None;
			}

			// 内分比を平面までの距離の比率を用いて求める
			return l1 / (l1 - l2);
		}

		bool PolygonInside(std::vector<Vector3> const& vertices, Vector3 const& point)
		{
			// ベクトル
			Vector3 v1 = vertices[1] - vertices[0];
			Vector3 v2 = point - vertices[0];

			// 法線
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
