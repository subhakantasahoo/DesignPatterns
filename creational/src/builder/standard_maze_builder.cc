// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "standard_maze_builder.h"

#include "../mazeparts/wall.h"
#include "../mazeparts/door.h"

namespace creational
{
	StandardMazeBuilder::StandardMazeBuilder() :current_maze_(nullptr)
	{
	}

	StandardMazeBuilder::~StandardMazeBuilder()
	{
		delete current_maze_;
	}

	void StandardMazeBuilder::BuildMaze()
	{
		current_maze_ = new Maze;
	}

	void StandardMazeBuilder::BuildRoom(const int& room_number)
	{
		auto room = new Room(room_number);
		current_maze_->AddRoom(room);

		room->SetSide(North, new Wall);
		room->SetSide(South, new Wall);
		room->SetSide(East, new Wall);
		room->SetSide(West, new Wall);
	}

	void StandardMazeBuilder::BuildDoor(const int& first_room_number, const int& second_room_number)
	{
		auto r1 = current_maze_->GetRoom(first_room_number);
		auto r2 = current_maze_->GetRoom(second_room_number);
		auto d = new Door(*r1, *r2);

		r1->SetSide(CommonWall(*r1, *r2), d);
		r2->SetSide(CommonWall(*r2, *r1), d);
	}

	Maze* StandardMazeBuilder::GetMaze()
	{
		return current_maze_;
	}

	Direction StandardMazeBuilder::CommonWall(const Room& first_room, const Room& second_room) const
	{
		auto r1_number = first_room.room_number();
		auto r2_number = second_room.room_number();
		if (r1_number < r2_number)
		{
			return East;
		}
		return West;
	}
}