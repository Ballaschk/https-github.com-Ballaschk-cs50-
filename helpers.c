// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    float k = fraction[0] - '0';
    float j = fraction[2] - '0';
    int duration = k / j * 8;
    return  duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int oct;
    char acc = -1;
    char n = note[0];

    if (strlen(note) == 2)
    {
        oct = note[1] - '0';
    }
    else
    {
        oct = note[2] - '0';
        acc = note[1];
    }
    double hertz;
    if (strcmp(note, "A4") == 0)
    {
        hertz = 440;
    }
    else
    {
        if (oct > 4)
        {
            int semitones = (oct - 4) * 12;
            hertz = pow(2, (semitones / 12)) * 440;
        }
        else
        {
            int semitones = (4 - oct) * 12;
            hertz = 440 / pow(2, (semitones / 12)) ;
        }
        if (acc == '#')
        {
            hertz = pow(2, (1.0 / 12.0)) * hertz;
        }
        else if (acc == 'b')
        {
            hertz = hertz / pow(2, (1.0 / 12.0));
        }
        switch (n)
        {
            case 'B':
                hertz = hertz * pow(2, (2.0 / 12.0));
                break;
            case 'C':
                hertz = hertz / pow(2, (9.0 / 12.0));
                break;
            case 'D':
                hertz = hertz / pow(2, (7.0 / 12.0));
                break;
            case 'E':
                hertz = hertz / pow(2, (5.0 / 12.0));
                break;
            case 'F':
                hertz = hertz / pow(2, (4.0 / 12.0));
                break;
            case 'G':
                hertz = hertz / pow(2, (2.0 / 12.0));
                break;
        }

    }
    return round(hertz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    return false;
}
