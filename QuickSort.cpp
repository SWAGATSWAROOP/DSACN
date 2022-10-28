void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int input[],int si,int ei){
    int piviot = input[si];
    int count = 0;
    for(int i=si+1;i<=ei;i++){
        if(piviot>=input[i]){
            count++;
        }
    }
    int piviotindex = si+count;
    swap(input[si],input[piviotindex]);
    int i = si,j=ei;
    while(i<piviotindex && j>piviotindex){
        while(input[i]<=piviot){
            i++;
        }
        while(input[j]>piviot){
            j--;
        }
        if(j>piviotindex && i<piviotindex){
            swap(input[i++],input[j--]);
        }
    }
    return piviotindex;
}

void QuickSort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int p = Partition(input,si,ei);
    QuickSort(input,si,p-1);
    QuickSort(input,p+1,ei);
}

void quickSort(int input[], int size) {
  	QuickSort(input,0,size-1);
}