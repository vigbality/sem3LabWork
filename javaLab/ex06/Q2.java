import mypack.converter.*;
public class Q2{
    public static void main(String[] args) {
        System.out.println("*************************************");
        DistanceConverter dObj= new DistanceConverter();
        System.out.println("Meter to KM>> 2340meter ==  " + dObj.meterToKm(2340)+" kms");
        System.out.println("KM to Meter>> 25.6 kms ==  " + dObj.kmToMeter(25.6)+" meters"); 
        System.out.println("Miles to KM>>23 miles == " + dObj.milesToKm(23)+" kms");
        System.out.println("KM to Miles>>36.8 kms == " + dObj.kmToMile(36.8)+" miles");
        System.out.println("*************************************");
    	TimeConverter tObj= new TimeConverter();
        System.out.println("Hours to minute>> 2.5 hours ==  " + tObj.hToM(2.5)+" minutes");
        System.out.println("Minute to Hour>> 45 mins ==  " + tObj.mToH(45)+" hours");
        System.out.println("Minutes to seconds>>43 minutes == " + tObj.mToS(43)+" Seconds");
        System.out.println("Seconds to minutes>>3600 seconds == " + tObj.sToM(3600)+" minutes");
    }
    
    
}
