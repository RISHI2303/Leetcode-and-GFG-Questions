class Solution {
    public double angleClock(int hour, int minutes) {
        
        double h = (hour%12 * 30) + ((double)minutes/60 * 30);
        
        double m = minutes * 6;
        
        double angle = Math.abs(m - h);
        
        if (angle > 180) angle = 360.0 - angle;
        
        return angle;
    }
}