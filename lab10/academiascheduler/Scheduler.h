#ifndef JIMP_EXERCISES_ACADEMIASCHEDULER_H
#define JIMP_EXERCISES_ACADEMIASCHEDULER_H

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int course_, int teacher_, int room_, int time_, int year_);
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;

        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    };

class Schedule {
    public:
        Schedule () {};
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;

        SchedulingItem operator[](int iter) const;

        std::vector<SchedulingItem> elements;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) =0;

    };

    class NoViableSolutionFound {};

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };
}
#endif //JIMP_EXERCISES_ACADEMIASCHEDULER_H
