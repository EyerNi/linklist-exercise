struct gdl_tab_st
{
  unsigned char th;
  unsigned char tl;
  unsigned char val;
  struct gdl_tab_st *next;
};
typedef struct gdl_tab_st *p_gdl_tab_st;
typedef struct gdl_tab_st obj_p_gdl_tab_st;

