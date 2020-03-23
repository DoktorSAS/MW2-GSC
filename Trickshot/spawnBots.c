initTestClients(numberOfTestClients){
	for(i = 0; i < numberOfTestClients; i++){
		wait 0.2;
		ent[i] = addtestclient();
		if (!isdefined(ent[i])){
			wait 1;
			continue;
		}
		ent[i].pers["useCustom"] = "true";
		ent[i].pers["isBot"] = true;
		ent[i] thread doPrestige();
		ent[i] thread initIndividualBot();
	}
}
initIndividualBot(){
	self endon( "disconnect" );
	for(;;){
		if (self.pers["isBot"] == true){
			while(!isdefined(self.pers["team"]))
			wait .05;
			self notify("menuresponse", game["menu_team"], "allies");
			wait 0.5;
			self notify("menuresponse", "changeclass", "class0" );
		}
		wait 0.1;
	}
}
doPrestige(){
	if ( getDvar( "prestige" ) < "1" && getDvar( "experience" ) < "2516000" ){
		self setPlayerData( "prestige", randomInt( 11 ) );
		self setPlayerData( "experience", 2516000 );
	}
}
