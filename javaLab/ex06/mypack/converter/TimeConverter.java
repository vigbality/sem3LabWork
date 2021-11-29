package mypack.converter;

public class TimeConverter {
	public double hToM(double h){
		return h*60;
	}
	public double mToS(double m){
		return m*60;
	}
	public double mToH(double m){
		return m/60;
	}
	public double sToM(double s){
		return s/60;
	}
}
