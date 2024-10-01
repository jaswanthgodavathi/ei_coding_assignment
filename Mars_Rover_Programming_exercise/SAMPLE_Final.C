#include<stdio.h>

int main(){
    int n,i,j;

//GETTING THE VALUES AND DOING A "DO WHILE" CHECK

    do{
        printf("\nENTER THE SIZE OF THE NxN MATRIX : ");
        scanf("%d",&n);
    }while(n<2);

//STORING THE VALUES IN MATRIX

    int array_ob[n*n];  //DECLARING THE MATRIX FOR STORING THE OBSTACLES
    int array_des[n*n]; //DECLARING THE MATRIX FOR STORING THE DESTINATION ONE 

    int array[n*n], size=-1;  //DECLARING THE MATRIX
    for(i=0;i<n;i++){
        
        for(j=0;j<n;j++){
            size=size+1;
            array[size]=size+11;
            array_des[size]=88;
            array_ob[size]=88;
        }
    }

// DISPLAYING THE MATRIX

    printf("\nTHIS IS THE %d*%d MATRIX :\n",n,n);
    size=-1;
    for(i=0;i<n;i++){
        
        for(j=0;j<n;j++){
            size=size+1;  
            //printf("%d",size);   cross check
            printf("%d \t",array[size]);
        }
        printf("\n");
    }

//GETTING THE TOTAL NUMBER OF OBSTACLES AND A "DO WHILE" CHECK

    int obs;
    printf("\n");
    do {
        printf("ENTER THE TOTAL NUMBER OF OBSTACLES :");
        scanf("%d",&obs);
    }while(obs<0 || obs>n);

//GETTING THE TOTAL OBSTACLES
    printf("\n");
    for (int loop=0; loop<obs; loop++){
        int obsv;

        //GETTING THE VALUE OF INDIVIDUAL OBSTACLE
        
        do{
            printf("ENTER OBSTACLE %d : ",loop+1);
            scanf("%d",&obsv);

            do{     // TO CHECK IF THE STARTING POINT IS AN OBSTACLE
                if (obsv==11){
                    printf("\nSORRY THE STARTING POINT CANNOT BE AN OBSTACLE : ");
                    printf("\nENTER OBSTACLE %d : ",loop+1);
                    scanf("%d",&obsv);
                }
            }while (obsv==11);

        }while ((obsv<11) || (obsv>n*n+11));   // "DO WHILE" CHECK FOR LESS THAN 11 AND GREATER THAN N SQUARE 
        
        //STORING THE VALUES OF OBSTACLES IN BOTH OBSTACLE AND DESTINATION ARRAY
        
        array_ob[obsv-11] = 99;
        array_des[obsv-11] = 99;
    }

//GETTING INPUT FOF DESTINATION

    int des;
    printf("ENTER THE DESTINATION : ");
    scanf("%d",&des);
    printf("\n");

//CHECKING CONDITIONS FOR DESTINATION

    while(des<11 || des>((n*n)+10)){
        printf("SORRY.. DESTINATION CANNOT BE OUT OF THE MATRIX : ");
        scanf("%d",&des);
    }
    for(i=0;i<=n*n-1;i++){
        if(array_ob[i] == 99 && i+11 == des){
            printf("SORRY.. DESTINATION CANNOT HAVE AN OBSTACLE : ");
            scanf("%d", &des);
            while(des < 11 || des > ((n*n)+11)){
                printf("SORRY.. DESTINATION CANNOT BE OUT OF THE MATRIX : ");
                scanf("%d",&des);
            }
        }
    }

// STORING ARRAY DESTINATION COLUMN ROW AND INDEX POSITION

    int m,array_val[4],loop,loop1,a,indexdes,rowdes,columndes;
    m=n;
    size=-1;
    for(loop=1;loop<=n;loop++){
        size=size+1;
        for(loop1=1;loop1<=m;loop1++){
            //printf("%d",size);
            if(array[size]==des){
               //printf("\nis going");
                array_des[size]=3;
                indexdes=size;
                columndes=loop1;
                rowdes=loop;
            }
            if(loop1==m){
                //printf("\nis");
            }
            else{
               // printf("\niiis");
                size+=1;
            }
        }
    }
    if(des>(n*n)+10||des<11){
        printf("SORRY! DESTINATION GIVEN OUT OF MATRIX");
        a=0;
    }
    else{
        a=1;
    }
    array_val[0]=indexdes;
    //  ARRAY4[0] = INDEX OF DESTINATION
    array_val[1]=columndes;
    //  ARRAY4[1] = COLUMN OF DESTINATION
    array_val[2]=rowdes;
    //  ARRAY4[2] = ROW OF DESTINATION
    array_val[3]=a;
    //  CONDITION TO RUN FURTHER PROGRAM

    /*CROSS CHECK CASES
    printf("%d\n",array_val[0]);
    printf("%d\n",array_val[1]);
    printf("%d\n",array_val[2]);
    printf("%d\n",array_val[3]);*/

//GENERAL COMPLEX CASES

int b,rods,colds,ids;
    rods=array_val[2];
    colds=array_val[1];
    ids=array_val[0];
    b=0;
    if(array_des[1]==99&&array_des[n]==99){
        printf("SORRY THE INITIAL POINT HAS BEEN BLOCKED BY BOTH SIDES BY OBSTACLES(RIGHT AND BELOW).");
        b=1;
    }
    else{ // worked
        if(array_des[ids]==array_des[n*n-1]){
            if(array_des[ids-1]==99&&array_des[ids-n]==99){
                printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED BY BOTH SIDES BY OBSTACLES(LEFT AND TOP)." );
                b=1;
            }
        }
        else{ // worked
            if(colds==n&&ids==n-1){
                if(array_des[ids-1]==99&&array_des[ids+n]==99){
                    printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED BY BOTH SIDES BY OBSTACLES(LEFT AND DOWN).");
                    b=1;
                }
            }
            else{ // worked
                if(rods==n&&ids==(n*n)-n){
                    if(array_des[ids+1]==99&&array_des[ids-n]==99){
                        printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED BY BOTH SIDES BY OBSTACLES(RIGHT AND TOP).");
                        b=1;}
                }
                else{// worked
                    if((ids>n*n-n+1) && ids<(n*n-1)){
                        if(array_des[ids-1]==99&&array_des[ids-n]==99&&array_des[ids+1]==99){
                            printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED THREE SIDES BY OBSTACLES.");
                            b=1;
                        }
                    }
                    else{//worked
                        if((ids<n-1)&&(ids>0)){
                            if(array_des[ids-1]==99&&array_des[ids+n]==99&&array_des[ids+1]==99){
                                printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED THREE SIDES BY OBSTACLES.");
                                b=1;
                            }
                        }
                        else{// worked
                            if(colds==1&&(ids>0)&&(ids<(n*n)-n)){
                                if(array_des[ids+1]==99&&array_des[ids-n]==99&&array_des[ids+n]==99){
                                        printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED THREE SIDES BY OBSTACLES.");
                                    b=1;
                                }
                            }
                            else{ //worked
                                if((rods>1&&rods<n)&&(colds>1)&&(colds<n)){
                                    if(array_des[ids+1]==99&&array_des[ids-1]==99&&array_des[ids+n]==99&&array_des[ids-n]==99){
                                        printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED FOUR SIDES BY OBSTACLES.");
                                        b=1;
                                    }
                                }
                                else{ //worked
                                    if(colds==n&&ids>n&&ids<(n*n)-1){
                                        if(array_des[ids+n]==99&&array_des[ids-1]==99&&array_des[ids-n]==99){
                                            printf("SORRY THE DESTINATION POINT HAS BEEN BLOCKED THREE SIDES BY OBSTACLES.");
                                            b=1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

//COMPLEX GENERAL CASES

    int val=0, xl=n, yl=0, zl=0, al, bl=1, loop2, count, c, d;
    ids=array_val[0];
    array_des[ids]=11;
    
    //CHECK FOR DIAGONAL
    for (loop=1;loop<=n;loop++){
        if (array_des[xl+yl-zl-1]==99){
            al=0;
            val+=1;
            for (loop2=1;loop2<=n-loop;loop2++){
                al+=1;
                if (array_des[xl+yl-zl-al]==array_des[ids]){
                    bl=0;
                }
            }
            
            if(val==n&&bl!=0){
                printf("SORRY YOU HAVE BEEN BLOCKED BY OBSTACLES");
                array_val[3]=1;
            }
        }
        zl+=1;
        yl+=n;
    }
    //CHECK FOR COLUMN 
    c=0;
    for(loop=1;loop<=n-1;loop++){
        count=0;
        for(loop2=loop;loop2<=n*n-1;loop2+=n){
            if(array_ob[loop2]==99){
                count+=1;
            }
        }
        if(count==n){
            d=0;
            a=0;
            for(loop2=loop;loop2<=n*n-1;loop2+=n){
                if(ids<loop2 && ids>=a){
                    c=1;
                }
                else{
                    d+=1;
                }
                a+=n;
            }
            if(c!=1 && d==n){
                printf("SORRY YOU HAVE BEEN BLOCKED BY OBSTACLE");
                array_val[3]=1;
                loop=n;
            }
        }
    }
    //CHECK FOR ROW
    for(loop=0;loop<=(n*n)-1;loop+=n){
        c=0;
        for(loop2=loop;loop2<=loop+n-1;loop2++){
            if(array_ob[loop2]==99){
                c+=1;
            }
        }
        if(c==n){
            loop2-=n+1;
            if(ids<loop2){
                continue;
            }
            else{
                printf("SORRY YOU HAVE BEEN BLOCKED BY OBSTACLE");
                array_val[3]=1;
            }
        }
    }

    int t, rd1=0, cd1=0, rd2, cd2;
    rods=array_val[2];
    colds=array_val[1];
    ids=array_val[0];
    if (rods>colds){
        c=-1;
    }
    else{
        c=-n;
    }
    t=-1;
    for(loop=0;loop<=n*n-1;loop++){
        if(rods>colds){
            if(0==ids){
                if(t<0){
                    printf("BINGO! FOUND YOUR PATH");
                    t=1;
                }     
            }
            else{
                cd1+=1;
                c+=1;
                if(c<n*n){
                    if(array_des[c]==99){
                        if(c<n){
                            int cl;
                            cl=c;
                            while(cl%n!=0){
                                if(array_des[cl-1]==11){
                                    array_des[cl-1]=88;
                                    cl-=1l;
                                }
                            }
                            c+=n-1;
                            colds-=1;
                        }
                        else{
                            int cl;
                            cl=c;
                            while(cl%n!=0){
                                if(array_des[cl-1]==11){
                                    array_des[cl-1]=88;
                                    cl-=1;
                                }
                            }
                            c=c-n-1;
                            colds-=1;
                        }
                    }
                    array_des[c]=11;
                }
            }
            if(cd1==colds){
                colds=rods+colds+1;
            }
        }
        else{
            if(c==ids||c-n==ids){
                if(t<0){
                    printf("BINGO! FOUND YOUR PATH");
                    t=1;
                }
            }
            else{
                rd1+=1;
                c+=n;
                if(c<n*n){
                    if(array_des[c]==99){
                        if(array_des[c-n+1]!=99){
                            c=c-n+1;
                            rd1-=1;
                        }
                    }
                    array_des[c]=11;
                }
            }
            if(rd1==rods){
                rods+=colds;
            }
        }
    }
    array_des[ids]=11;


// DISPLAYING THE OUTPUT ARRAY

    printf("\nTHIS IS YOUR FINAL PATH OF YOUR %d*%d MATRIX :\n\n",n,n);
    size=-1;
    for(i=0;i<n;i++){
        
        for(j=0;j<n;j++){
            size=size+1;  
            //printf("%d",size);   CROSS CHECK
            printf("%d \t",array_des[size]);
        }
        printf("\n");
    }
    
}