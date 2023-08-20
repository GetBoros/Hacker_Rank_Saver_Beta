#pragma once

class AsSingleton
{
public:
	AsSingleton(const AsSingleton&) = delete;

	static AsSingleton &Get();

	static float Float();

private:
	AsSingleton();

	float IFloat();  // Internal || Implementation

	float Random_Generator = 0.5f;
};

