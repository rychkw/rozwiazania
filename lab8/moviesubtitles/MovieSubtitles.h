#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <iostream>

using namespace std;

namespace moviesubs{

    class MovieSubtitles {
    public:
        MovieSubtitles(){}
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        MicroDvdSubtitles(){}
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class SubRipSubtitles : public MovieSubtitles{
    public:
        SubRipSubtitles(){}
        virtual void ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);
    };

    class SubtitlesException : public invalid_argument{
    public:
        SubtitlesException(const string &str ) : invalid_argument::invalid_argument(str){};
        int LineAt1() const;
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift();
    };

    class SubtitleEndBeforeStart : public SubtitlesException{
    public:
        SubtitleEndBeforeStart(int line_number,string line);
        int LineAt() const;

    private:
        int line_number;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat();
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        MissingTimeSpecification();
    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        OutOfOrderFrames();
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
