int PairCount=0;

void Algo_Initialize(){
	
}

void PushTile(tile T){
	if (Singles[T.color][T.number]){
		PairCount++;
		MoveTile(T);
		MoveTile(T);
	}
	Singles[T.color][T.number]=!Singles[T.color][T.number];
}

bool TestHu(tile T){
	return PairCount==6 && Singles[T.color][T.number];
}

// decide which one to out or hu
void ActionAfterPick(tile T){
	int minc;
	tile mint;
	if (TestHu(T)){
		Hu();
		return;
	}
	PushTile(T);
	mint=*Hand.begin();
	minc=RTiles[mint.color][mint.number];
	for (vit it=Hand.begin();it!=Hand.end();it++){
		if (RestTile(*it)<minc){
			mint=*it;
			minc=RestTile(*it);
		} else if (RestTile(*it)>minc) {
			if (abs((*it).number-5)>abs(mint.number-5)){
				mint=*it;
			}
		}
	}
	Out(mint);
}

// decide action to take after one giving out a tile
void ActionAfterMOut(tile T){
	if (TestHu(T)){
		Hu();
		return;
	}
	cout<<"pass"<<endl;
}


