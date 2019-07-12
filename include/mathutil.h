string to_string(int a){
  std::string p;
  std::stringstream ss;
  ss << a;
  p = ss.str();
  return p;
}
float fmod(float x, float y)
{
	int q = floor(x / y);
	return x - (float)q * y;
}

float degToRad(float degrees)
{
	return degrees * PI / 180;
}

float radToDeg(float radians)
{
	return radians * 180 / PI;
}