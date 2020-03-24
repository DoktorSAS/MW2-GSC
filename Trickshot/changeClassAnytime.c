changeClassAnytime(){ //Made By DoktorSAS
	self endon("disconnect");
	level endon( "game_ended" );
	for(;;){
		oldclass = self.pers["class"];
		wait 0.05;
		if(self.pers["class"] != oldclass){
			self maps\mp\gametypes\_class::giveloadout(self.pers["team"],self.pers["class"]);
			qoldclass = self.pers["class"];
		}
	}
}