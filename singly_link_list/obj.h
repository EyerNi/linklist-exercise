#define dereference(x) obj_##x
struct gdl_tab_st
{
  unsigned char th;
  unsigned char tl;
  unsigned char val;
  struct gdl_tab_st *next;
};
typedef struct gdl_tab_st *p_gdl_tab_st;
typedef struct gdl_tab_st obj_p_gdl_tab_st;

/**
 * @brief
 *
 */
#define gen_a_nod_with_val(chain_type, des, src, the_next) \
  new_a_nod(chain_type, des);                              \
  copy_a_nod(chain_type, des, src, the_next)

#define new_a_nod(chain_type, x)                                      \
  chain_type x = (chain_type)malloc(sizeof(dereference(chain_type))); \
  if (x == NULL)                                                      \
    return x;

#define copy_a_nod(chain_type, des, src, the_next)   \
  memcpy(des, src, sizeof(dereference(chain_type))); \
  des->next = the_next;

#define sll_insert_head(name, h, v) insert_##name##_chain_head(h, v)
#define sll_insert_tail(name, h, v) insert_##name##_chain_tail(h, v)
#define sll_insert_pos(name, h, v, i) insert_##name##_chain_by_index_base_0(h, v, i)
#define sll_insert_free(name, h) free_##name##_chain(h)
/**
 * @brief
 *
 */
#define install_singly_linked_list(chain_type)                                                                         \
  chain_type insert_##chain_type##_chain_head(chain_type nod_head, chain_type nod_obj);                                \
  chain_type                                                                                                           \
      insert_##chain_type##_chain_head(chain_type nod_head, chain_type nod_obj)                                        \
  {                                                                                                                    \
    gen_a_nod_with_val(chain_type, nod_new, nod_obj, nod_head);                                                        \
    return nod_new;                                                                                                    \
  }                                                                                                                    \
  chain_type insert_##chain_type##_chain_tail(chain_type nod_head, chain_type nod_obj);                                \
  chain_type                                                                                                           \
      insert_##chain_type##_chain_tail(chain_type nod_head, chain_type nod_obj)                                        \
  {                                                                                                                    \
    if (nod_head == NULL)                                                                                              \
      return insert_##chain_type##_chain_head(nod_head, nod_obj);                                                      \
    gen_a_nod_with_val(chain_type, nod_new, nod_obj, NULL);                                                            \
    chain_type cur = nod_head;                                                                                         \
    while (1)                                                                                                          \
    {                                                                                                                  \
      if (cur->next == NULL)                                                                                           \
        break;                                                                                                         \
      cur = cur->next;                                                                                                 \
    }                                                                                                                  \
    cur->next = nod_new;                                                                                               \
    return nod_head;                                                                                                   \
  }                                                                                                                    \
  chain_type insert_##chain_type##_chain_by_index_base_0(chain_type nod_head, chain_type nod_obj, unsigned nod_index); \
  chain_type                                                                                                           \
      insert_##chain_type##_chain_by_index_base_0(chain_type nod_head, chain_type nod_obj, unsigned nod_index)         \
  {                                                                                                                    \
    if (nod_head == NULL)                                                                                              \
      return insert_##chain_type##_chain_head(nod_head, nod_obj);                                                      \
    chain_type cur = nod_head;                                                                                         \
    unsigned i = 0;                                                                                                    \
    while (1)                                                                                                          \
    {                                                                                                                  \
      if (cur == NULL)                                                                                                 \
        break;                                                                                                         \
      if (i == nod_index)                                                                                              \
        break;                                                                                                         \
      i++;                                                                                                             \
      cur = cur->next;                                                                                                 \
    }                                                                                                                  \
    if (cur == NULL)                                                                                                   \
      return nod_head;                                                                                                 \
    gen_a_nod_with_val(chain_type, nod_new, nod_obj, NULL);                                                            \
    nod_new->next = cur->next;                                                                                         \
    cur->next = nod_new;                                                                                               \
    return nod_head;                                                                                                   \
  }                                                                                                                    \
  chain_type free_##chain_type##_chain(chain_type nod_head);                                                           \
  chain_type                                                                                                           \
      free_##chain_type##_chain(chain_type nod_head)                                                                   \
  {                                                                                                                    \
    chain_type cur = nod_head;                                                                                         \
    nod_head = NULL;                                                                                                   \
    while (1)                                                                                                          \
    {                                                                                                                  \
      if (cur == NULL)                                                                                                 \
        break;                                                                                                         \
      chain_type not_null = cur;                                                                                       \
      cur = cur->next;                                                                                                 \
      free(not_null);                                                                                                  \
    }                                                                                                                  \
    return nod_head;                                                                                                   \
  }

