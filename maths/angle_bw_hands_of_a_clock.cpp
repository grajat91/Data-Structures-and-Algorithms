/*
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 3, minutes = 30
Output: 75

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5
 
Constraints:
1 <= hour <= 12
0 <= minutes <= 59
*/

    double angleClock(int hour, int minutes) {
     /*
     Hour Hand
     In 12 hours Hour hand complete whole circle and cover 360°
     So, 1 hour = 360° / 12 = 30°

     Since 1 hours = 30°
     In 1 minute, hours hand rotate -> 30° / 60 = 0.5°
     So total angle because of minutes by hour hand is minutes/60 * 30 or minutes * 0.5
 
     Minute Hand
     In 60 minutes Minute Hand completes whole circle and cover 360°.
     So, 1 minute -> 360° / 60 = 6°
     */
        double hour_angle = (hour%12)*30 + ((double)minutes*0.5) ;
        double minute_angle = 6*minutes;
        double diff = abs(minute_angle - hour_angle);
        if (diff > 180) diff = 360-diff;
        return diff;
    }
