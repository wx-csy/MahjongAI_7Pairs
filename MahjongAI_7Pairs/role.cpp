int ID;
int HandCount[10][10];
tiles Hand;

void Starting(){
	string str;
	
	cout<<"join"<<endl;
	
	cin>>str>>ID;
	assert(str=="id"); 
	
	cin>>str>>FirstPlayerID;
	assert(str=="first");
	
	cin>>str;
	assert(str=="init");
	for (int i=0;i<13;i++){
		cin>>str;
		Hand.push_back(MakeTile(str));
		PushTile(MakeTile(str));
		AppearTile(MakeTile(str));
	}
	
	Algo_Initialize();
}

void Gaming(){
	string str;
	string ntile;
	tile T;
	int a,b,c;
	while(true){
		cin>>str;
		if (str=="pick"){
			cin>>ntile;
			T=MakeTile(ntile);
			AppearTile(T);
			Hand.push_back(T);
			ActionAfterPick(T);
		}
		if (str=="mpick"){
			cin>>a;
		}
		if (str=="mout"){
			cin>>a>>ntile;
			AppearTile(MakeTile(ntile));
			ActionAfterMOut(MakeTile(ntile));
		}
		if (str=="mchi"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			AppearTile(T);
			T.number++;
			AppearTile(T);
			T.number++;
			AppearTile(T);
		}
		if (str=="mpeng"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			AppearTile(T);AppearTile(T);AppearTile(T);
		}
		if (str=="mgang"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			AppearTile(T);AppearTile(T);AppearTile(T);AppearTile(T);
		}
		if (str=="magang"){
			cin>>a;
		}
		if (str=="mjgang"){
			cin>>a>>ntile;
			AppearTile(MakeTile(ntile));
			if (TestHu(MakeTile(ntile))) QiangGang();
		}
		if (str=="mhu"){
			cin>>a>>b>>c;
			break;
		}
		if (str=="mfail"){
			
		}
		sort(Hand.begin(),Hand.end());
	}
}

int CountTile(tile T){
	int result=0;
	for (vit it=Hand.begin();it!=Hand.end();it++){
		if (*it==T) result++;
	}
	return result;
}

void AddTile(tile T){
	Hand.push_back(T);
}

void MoveTile(tile T){
	for (vit it=Hand.begin();it!=Hand.end();it++)
		if (*it==T) {
			Hand.erase(it);
			return;
		}
}

void Out(tile T){
	cout<<"out "<<Tile2Str(T)<<endl;
	MoveTile(T);
	Singles[T.color][T.number]=false;
}

void Chi(tile T){
	cout<<"chi "<<Tile2Str(T)<<endl;
} 

void Peng(){
	cout<<"peng"<<endl;
} 

void Gang(){
	cout<<"gang"<<endl;
}

void JiaGang(tile T){
	cout<<"jgang "<<Tile2Str(T)<<endl;
}

void AnGang(tile T){
	cout<<"agang "<<Tile2Str(T)<<endl;
}

void Pass(){
	cout<<"pass"<<endl;
}

void QiangGang(){
	cout<<"qgang"<<endl;
}

void Hu(){
	cout<<"hu"<<endl;
}

