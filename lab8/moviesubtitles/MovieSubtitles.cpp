#include "MovieSubtitles.h"

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

        int con = 1000;
        int start, stop;
        string tmp, subs;
        subs = (*in).str();

        if (fps <= 0) {
            throw std::invalid_argument("Invalid argument");
        }

        if (!regex_search (subs, regex("(\\{)[0-9]+(\\}\\{)[0-9]+(\\})(.*)(\n\\{)[0-9]+(\\}\\{)[0-9]+(\\})(.*)\n"))){
           throw InvalidSubtitleLineFormat();
        }
        int lines = 0;
        string INT_ON, INT_OFF, text;
        for(int i = 0; i < subs.length(); i++){
            if(subs[i] == '\n') {
                lines++;
                *out << subs[i];
            }
            else if(subs[i] == '{' && isdigit(subs[i+1])){
                INT_ON = "";
                INT_OFF = "";
                text = "";
                i++;
                while(subs[i] != '}') {
                    INT_ON += subs[i];
                    i++;
                }
                i += 2;
                while(subs[i] != '}'){
                    INT_OFF += subs[i];
                    i++;
                }
                text += '{' + INT_ON + '}' + '{' + INT_OFF + '}';
                start = stoi(INT_ON) + (delay * fps / con);
                stop = stoi(INT_OFF) + (delay * fps / con);
                if ( start < 0 || stop < 0 ){
                    throw NegativeFrameAfterShift();
                }
                *out << '{' + to_string(start) + '}';
                *out << '{' + to_string(stop) + '}';
            }
            else {
                text += subs[i];
                *out << subs[i];
            }
        }

        if(INT_ON >= INT_OFF) throw SubtitleEndBeforeStart(lines, text);
    }


    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {
    }
    
    NegativeFrameAfterShift::NegativeFrameAfterShift() : SubtitlesException("NegativeFrameAfterShift") {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_num, string line) : SubtitlesException ("At line " + std::to_string(line_num) + ": " + line) {
        line_number=line_num;
    }
    int SubtitleEndBeforeStart::LineAt() const {
        return line_number;
    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : SubtitlesException("InvalidSubtitleLineFormat") {}

    MissingTimeSpecification::MissingTimeSpecification() : SubtitlesException("MissingTimeSpecification") {}

    OutOfOrderFrames::OutOfOrderFrames() : SubtitlesException("OutOfOrderFrames") {}




    void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

        // INDEX   NEW_LINE   TIME_IN  →  TIME_OFF   NEW_LINE   SUBTITLE1   NEW_LINE   SUBTITLE2   NEW_LINE   NEW_LINE
        //                    hh:mm:ss,mmm

        regex pattern_full {R"((\d\n)(\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3})(\n)(.*)(\n)(.*)(\n\n))"};

        regex pattern {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
        regex pattern_frame_order {R"((\n\d\n))"};
        regex wrong_pattern {R"(^\d$)"};

        smatch correct_form;
        smatch frame_order;
        smatch frame;

        int con = 1000;
        bool flag = false;
        int line_number = 0;

        if(fps < 0 )
            throw std::invalid_argument("invalid argument");

        string input_text = (*in).str();
        
        string tmp="";
        int i = 0;
        while (input_text[i] != '\n'){
            tmp += input_text[i];
            i++;
        }
        int nr = stoi(tmp);
        
        std::regex_search(input_text, frame_order, pattern_frame_order);
        nr+=1;
        for(int i = 1; i < frame_order.size() ; i++)
        {
            if (stoi(frame_order[i]) != nr)
                throw OutOfOrderFrames();
            nr++;
        }

        string current_line = "";
        while(getline(*in,current_line,'\n')) {

            // INDEX   NEW_LINE   TIME_IN  →  TIME_OFF   NEW_LINE   SUBTITLE1   NEW_LINE   SUBTITLE2   NEW_LINE   NEW_LINE
           
            if (std::regex_search(current_line, correct_form, pattern)) {
                line_number++;
                flag = false;

                //           hh:mm:ss,mmm      hh:mm:ss,mmm
                //            1: 2: 3, 4        5: 6: 7, 8

                *out << correct_form[1] << ":" << correct_form[2] << ":";

                string mmm1 = correct_form[4];
                string mmm2 = correct_form[8];

                int mm1 = stoi(correct_form[4]);
                int mm2 = stoi(correct_form[8]);
                int mn1 = stoi(correct_form[3]);
                int mn2 = stoi(correct_form[7]);

                
                int mmm1_delayed = mm1 + delay;
                int mmm2_delayed = mm2 + delay;
                
                int sec1_delayed = mn1+mmm1_delayed/con;
                int sec2_delayed = mn2+mmm2_delayed/con;
                
                string sec1 = to_string(sec1_delayed);
                string sec2 = to_string(sec2_delayed);

                if(mmm1_delayed < con) {
                    if (sec1.size()<2) {
                        sec1 = '0' + sec1;
                    }
                    (*out)<< sec1 << "," << mmm1_delayed << " --> ";
                }
                else {
                    mmm1 = to_string(mmm1_delayed%con);
                    if(mmm1.size()<3) {
                        mmm1 = '0' + mmm1;
                    }
                    if(sec1.size()<2) {
                        sec1 = '0' + sec1;
                    }

                    (*out)<< sec1 << "," << mmm1 << " --> ";
                }

                *out << correct_form[5] << ":" << correct_form[6] << ":";
                
                if(mmm2_delayed < con)
                {
                    if(sec2.size() < 2) {
                        sec2 = '0' + sec2;
                    }

                    (*out)<< sec2 << "," << mmm2 << " --> ";
                }
                else{
                    mmm2 = to_string(mmm2_delayed%con);

                    if(mmm2.size() < 3) {
                        mmm2 = '0' + mmm2;
                    }
                    if(sec2.size() < 2) {
                        sec2 = '0' + sec2;
                    }

                    (*out)<< sec2 << "," << mmm2 << '\n';
                }

                int hr1 = stoi(correct_form[1]);
                int min1 = stoi(correct_form[2]);
                int hr2 = stoi(correct_form[5]);
                int min2 = stoi(correct_form[6]);

                if ((hr1 * 3600 + min1 * 60 + mn1 + mm1 * 0.001) >= (hr2 * 3600 + min2 * 60 + mn2 + mm2 * 0.001)) {
                    throw moviesubs::SubtitleEndBeforeStart(line_number, current_line);
                }

                if(sec1_delayed < 0 || mmm1_delayed < 0 || sec2_delayed < 0 || mmm2_delayed < 0 || hr1 < 0 || min1 < 0 || hr2 < 0 || min2 < 0 ) {
                    throw NegativeFrameAfterShift();
                }


            }
            else {
                if(flag == true) {
                    throw InvalidSubtitleLineFormat();
                }
                if (std::regex_search(current_line, frame, wrong_pattern)) {
                    flag = true;
                }

                *out << current_line << '\n';
            }
        }
    }
}