// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "composite_equipment.h"

namespace structural
{
namespace composite
{
CompositeEquipment::CompositeEquipment(const std::string& name) : name_(name), price_(0), power_(0)
{
	equipment_ = new operational::iterator::List<EquipmentInterface*>();
}

CompositeEquipment::CompositeEquipment() : CompositeEquipment("") { }

CompositeEquipment::~CompositeEquipment()
{
	delete equipment_;
}

std::string CompositeEquipment::name() const
{
	return name_;
}

Currency CompositeEquipment::price() const
{
	return price_;
}

void CompositeEquipment::price(const Currency& price)
{
	price_ = price;
}

Watt CompositeEquipment::power() const
{
	return power_;
}

void CompositeEquipment::power(const Watt& power)
{
	power_ = power;
}

Currency CompositeEquipment::NetPrice()
{
	auto i = CreateIterator();
	auto total = price_.value();

	for (i->First(); !i->IsDone(); i->Next())
	{
		auto current_item = i->CurrentItem();
		auto price = current_item->NetPrice();
		total += price.value();
	}
	delete i;

	return Currency(total);
}

Currency CompositeEquipment::DiscountPrice()
{
	auto net_price = NetPrice();
	auto discount_price = net_price.value() * 0.8;
	return Currency(discount_price);
}

void CompositeEquipment::Add(EquipmentInterface* equipment)
{
	equipment_->Append(equipment);
}

void CompositeEquipment::Remove(EquipmentInterface* equipment)
{
	equipment_->Remove(equipment);
}

operational::iterator::IteratorInterface<EquipmentInterface*> *CompositeEquipment::CreateIterator()
{
	return new operational::iterator::ListIterator<EquipmentInterface*>(equipment_);
}
}
}

