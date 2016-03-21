#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct point{
    int x;
    int y;
}st_point, *pst_point;

typedef enum flag{
    LINE,        /*横线  —— */
    V_LINE,      /*竖线  |  */
    SLASH,      /* 斜线 /  */
    BACK_SLASH   /* 反斜线\ */
}enflag;

typedef struct line{
    st_point p1;
    st_point p2;
    enflag fg;
}st_line,*pst_line;

typedef struct testcase{
    pst_line LineHead;
    int count;
}st_testcase,*pst_testcase;

//判断点是否在两点连线上
bool isPointOnLine(const pst_line pL, const pst_point pP)
{
    if((pL->p1.x >= pP->x && pL->p2.x <= pP->x) ||
       (pL->p1.x <= pP->x && pL->p2.x >= pP->x))
    {
        if(pL->p1.y==pL->p2.y && pL->p2.y == pP->y)
        {
            return true;
        }
        
        if(((pL->p1.x - pP->x)/(pL->p1.y - pP->y)) == 
        ((pL->p2.x - pP->x)/(pL->p2.y - pP->y)))
        {
            return true;
        }
    }

    return false;
}

//判断两条线是否重合
bool isOverLapLine(const pst_line pline1, const pst_line pline2, enflag _fg)
{
    switch(_fg)
    {
        case LINE:
        {
            if(pline1->p1.y != pline2->p1.y)
            {
                return false;
            }
            else if(isPointOnLine(pline1, &(pline2->p1)) || 
                    isPointOnLine(pline1, &(pline2->p2)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case V_LINE:
        {
            if(pline1->p1.x != pline2->p1.x)
            {
                return false;
            }
            else if(isPointOnLine(pline1, &(pline2->p1)) || 
                    isPointOnLine(pline1, &(pline2->p2)))
            {
                return true;
            }
            else
            {
                return false;
            }           
        }
        case SLASH:
        {
            if(isPointOnLine(pline1, &(pline2->p1)) || 
               isPointOnLine(pline1, &(pline2->p2)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case BACK_SLASH:
        {
            if(isPointOnLine(pline1, &(pline2->p1)) || 
               isPointOnLine(pline1, &(pline2->p2)))
            {
                return true;
            }
            else
            {
                return false;
            }            
        }
        default:
        {
            break;
        }
    }
}
int main()
{
    pst_testcase pHeadcase;
    int caseNum;
    int i;
    int LineCount;
    st_point p1,p2;
    
    scanf("%d",&caseNum);
    pHeadcase = (pst_testcase)malloc(caseNum*sizeof(st_testcase));
    i=0;
    for(; i<caseNum; i++)
    {
        scanf("%d",&LineCount);
        pHeadcase[i].count = LineCount;
        pHeadcase[i].LineHead = (pst_line)malloc(LineCount*sizeof(st_line));
        
        for(; LineCount>0; LineCount--)
        {
            
            scanf("%d",&p1.x);
            scanf("%d",&p1.y);
            scanf("%d",&p2.x);
            scanf("%d",&p2.y);
            
            pHeadcase[i].LineHead[LineCount].p1.x = p1.x;
            pHeadcase[i].LineHead[LineCount].p1.y = p1.y;
            pHeadcase[i].LineHead[LineCount].p2.x = p2.x;
            pHeadcase[i].LineHead[LineCount].p2.y = p2.y;
            
            if(p1.x==p2.x)
            {
                /*  竖线  | */
                pHeadcase[i].LineHead[LineCount].fg = V_LINE;
            }
            else if(p1.y==p2.y)
            {
                /*  横线 —— */
                pHeadcase[i].LineHead[LineCount].fg = LINE;                
            }
            else if(((p1.x-p2.x)/(p1.y-p2.y)) > 0)
            {
                /*  斜线 / */
                pHeadcase[i].LineHead[LineCount].fg = SLASH;
            }
            else
            {
                /*  反斜线 \ */
                pHeadcase[i].LineHead[LineCount].fg = BACK_SLASH;
            }
        }
    }
    
    i = caseNum;
    for(; i > 0; i--)
    {
        //计算能消减的数目
        LineCount = pHeadcase[i].count;
        int j;
        
        for(; LineCount>0; LineCount--)
        {
            j=0;
            switch(pHeadcase[i].LineHead[LineCount].fg){
                case LINE:
                {
                    for(;j < LineCount; j++)
                    {
                        if(pHeadcase[i].LineHead[j].fg == LINE)
                        {
                            //判断是否可消减
                            if(isOverLapLine(&(pHeadcase[i].LineHead[j]), &(pHeadcase[i].LineHead[LineCount]), LINE))
                            {
                                if(pHeadcase[i].count > 1)
                                {
                                    pHeadcase[i].count -= 1;
                                }
                            }
                        }
                    }
                }
                case V_LINE:
                {
                    for(;j < LineCount; j++)
                    {
                        if(pHeadcase[i].LineHead[j].fg == V_LINE)
                        {
                            //判断是否可消减
                            if(isOverLapLine(&(pHeadcase[i].LineHead[j]), 
                            &(pHeadcase[i].LineHead[LineCount]), V_LINE))
                            {
                                if(pHeadcase[i].count > 1)
                                {
                                    pHeadcase[i].count -= 1;
                                }
                            }                            
                        }
                    }                    
                }
                case SLASH:
                {
                    for(;j < LineCount; j++)
                    {
                        if(pHeadcase[i].LineHead[j].fg == SLASH)
                        {
                            //判断是否可消减
                            if(isOverLapLine(&(pHeadcase[i].LineHead[j]), \
                            &(pHeadcase[i].LineHead[LineCount]), SLASH))
                            {
                                if(pHeadcase[i].count > 1)
                                {
                                    pHeadcase[i].count -= 1;
                                }
                            }                             
                        }
                    }   
                }
                case BACK_SLASH:
                {
                    for(;j < LineCount; j++)
                    {
                        if(pHeadcase[i].LineHead[j].fg == BACK_SLASH)
                        {
                            //判断是否可消减
                            if(isOverLapLine(&(pHeadcase[i].LineHead[j]), \
                            &(pHeadcase[i].LineHead[LineCount]), BACK_SLASH))
                            {
                                if(pHeadcase[i].count > 1)
                                {
                                    pHeadcase[i].count -= 1;
                                }
                            } 
                        }
                    }                       
                }
            }
        }
        
    }
	i=0;
	for(;i < caseNum; i++)
	{
		printf("%d\n", pHeadcase[i].count);
	}	   

    return 0;
}
