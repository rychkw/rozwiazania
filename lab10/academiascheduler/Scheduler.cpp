#include "Scheduler.h"

namespace academia {
    SchedulingItem::SchedulingItem(int course0, int teacher0, int room0, int time0, int year0) {
        course_id = course0;
        teacher_id = teacher0;
        room_id = room0;
        time_slot = time0;
        year = year0;
    }

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }


    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule Tsch;

        std::copy_if(elements.begin(), elements.end(), std::back_inserter(Tsch.elements),
                     [teacher_id](SchedulingItem it) { return teacher_id == it.TeacherId(); });

        return Tsch;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule Rsch;

        std::copy_if(elements.begin(), elements.end(), std::back_inserter(Rsch.elements),
                     [room_id](SchedulingItem it) { return room_id == it.RoomId(); });

        return Rsch;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule Ysch;

        std::copy_if(elements.begin(), elements.end(), std::back_inserter(Ysch.elements),
                     [year](SchedulingItem it) { return year == it.Year(); });

        return Ysch;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> available;
        for (int i = 1; i <= n_time_slots; i++) {
            int free_slot = 1;
            for (auto it : elements) {
                if (it.TimeSlot() == i) {
                    free_slot = 0;
                }
            }
            if (free_slot != 0) {
                available.push_back(i);
            }
        }
        return available;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        elements.push_back(item);
    }

    size_t Schedule::Size() const {
        return elements.size();
    }

    SchedulingItem Schedule::operator[](int iter) const {
        return elements[iter];
    }


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule assigned{};

        int time=0, room = 0;

        for (auto t_c_a : teacher_courses_assignment) { //teacher  - course
            if ((t_c_a.second.size() >= n_time_slots)) {
                throw NoViableSolutionFound();
            }
            for(auto t_c : t_c_a.second) {  // course
                for (auto y_c : courses_of_year) { //year - course
                    if ((y_c.second.size() >= n_time_slots)) {
                        throw NoViableSolutionFound();
                    }
                    for (auto c : y_c.second) {  // course  
                        if (t_c == c ) { // znajdz pasujacy kurs
                            assigned.InsertScheduleItem(SchedulingItem{c, t_c_a.first, rooms[room], time, y_c.first});
                                                                       //course, teacher, room, time, year
                            room++;
                            time++;
                            break;
                        }
                    }
                }
            }
        }
        return assigned;
    }

}