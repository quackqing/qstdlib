#include <iostream>

#ifndef PI
#define PI (4 * atan(1))
#endif

// 地球的半长轴（单位：米）
const double WGS84_A = 6378137.0;

// 地球的扁率（单位：无单位）
const double WGS84_F = 1.0 / 298.257223563;

// 将角度转换为弧度
double toRadians(double degrees)
{
  return degrees * PI / 180.0;
}

// 计算两点之间的距离（单位：米）
unsigned int distance(double lat1, double lon1, double alt1,
                      double lat2, double lon2, double alt2)
{
  // 将经纬度转换为弧度
  double phi1 = toRadians(lat1);
  double lambda1 = toRadians(lon1);
  double phi2 = toRadians(lat2);
  double lambda2 = toRadians(lon2);

  // 计算两点之间的大圆弧长度
  double deltaLambda = lambda2 - lambda1;
  double deltaPhi = phi2 - phi1;
  double a = pow(sin(deltaPhi / 2), 2) + cos(phi1) * cos(phi2) * pow(sin(deltaLambda / 2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  // 使用WGS84椭球体模型计算地球的半长轴和扁率
  double eSquared = 2 * WGS84_F - pow(WGS84_F, 2);
  double aTimesE = WGS84_A * eSquared;

  // 计算两点之间的曲率半径
  double R1 = WGS84_A * (1 - eSquared) / pow(1 - eSquared * pow(sin(phi1), 2), 1.5);
  double R2 = WGS84_A * (1 - eSquared) / pow(1 - eSquared * pow(sin(phi2), 2), 1.5);

  // 计算地球的半径
  double radius = (R1 + R2) / 2;

  // 计算两点之间的水平距离
  double horizontalDistance = radius * c;

  // 计算两点之间的垂直距离
  double verticalDistance = abs(alt2 - alt1);

  // 计算总距离
  double dist = sqrt(pow(horizontalDistance, 2) + pow(verticalDistance, 2));
  unsigned int retDis = dist;
  return dist;
}

int main()
{
  std::cout << "Hello, World!" << std::endl;
  // 示例经纬度和高度
  double lat1 = 25.0;
  double lon1 = 121.0;
  double alt1 = 1000.0;

  double lat2 = 24.0000;
  double lon2 = 121.0;
  double alt2 = 1000.0;

  // 计算两点之间的距离
  unsigned int dist = distance(lat1, lon1, alt1, lat2, lon2, alt2);
  std::cout << "Distance between Shanghai and Beijing: " << dist << " kilometers" << std::endl;

  return 0;
}
