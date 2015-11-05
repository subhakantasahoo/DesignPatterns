// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_WINDOW_IMP_H_
#define STRUCTURAL_BRIDGE_WINDOW_IMP_H_

#include<string>

namespace structural
{
namespace bridge
{
class WindowImp
{
	public:
	virtual ~WindowImp() { }

	virtual void DeviceRect(float, float, float, float) = 0;
	virtual void DeviceText(const std::string& text, float, float) = 0;
};
}
}

#endif

