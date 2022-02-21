
#define SET_BIT(Var,BitNo)    Var |=  (1 << (BitNo))
#define CLR_BIT(Var,BitNo)    Var &= ~(1 << (BitNo))
#define TOG_BIT(Var,BitNo)    Var ^=  (1 << (BitNo))
#define GET_BIT(Var,BitNo)    1&(Var >> (BitNo))
#define SET_BYTE(Var,value)    Var= value
#define CLR_BYTE(Var)    Var =0
#define TOG_BYTE(Var)    Var= ~Var
