#pragma once

#include "application.h"

class HelloWindowApp final : public Application 
{
public:
	HelloWindowApp(const std::string& title);

protected:
	bool Load() override;
	void Render() override;
	void Update() override;
};