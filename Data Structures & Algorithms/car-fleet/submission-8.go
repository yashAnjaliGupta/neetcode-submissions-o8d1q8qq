type Car struct{
	position int;
	speed int;
}
func carFleet(target int, position []int, speed []int) int {
	n:=len(position);
	var cars = make([]Car, n);
	for i:=0;i<n;i++ {
		cars[i]=Car{position[i],speed[i]};
	}
	sort.Slice(cars,func(i,j int)bool{
		return cars[i].position > cars[j].position;
	} );
	var fleets []float64;
	for i:=0;i<n;i++ {
		var time = float64(target-cars[i].position) / float64(cars[i].speed);
		if len(fleets) == 0 || time > fleets[len(fleets)-1] {
			fleets=append(fleets,time);
		}
	}
	return len(fleets);
}
