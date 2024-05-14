/**
 * @file obj.c
 * @author EyerNi (eyerni@void.com)
 * @brief
 * @version 0.1
 * @date 2024-05-07
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mcheck.h>
#include "obj.h"

install_singly_linked_list(p_gdl_tab_st);

int main()
{
  mtrace();

  p_gdl_tab_st gdl_head = NULL;

  dereference(p_gdl_tab_st) test_obj;

  test_obj.th = 10;
  test_obj.tl = 20;
  test_obj.val = 151;
  gdl_head = sll_insert_tail(p_gdl_tab_st, gdl_head, &test_obj);

  test_obj.th = 20;
  test_obj.tl = 30;
  test_obj.val = 161;
  gdl_head = sll_insert_tail(p_gdl_tab_st, gdl_head, &test_obj);

  test_obj.th = 40;
  test_obj.tl = 50;
  test_obj.val = 171;
  gdl_head = sll_insert_tail(p_gdl_tab_st, gdl_head, &test_obj);

  test_obj.th = 0;
  test_obj.tl = 10;
  test_obj.val = 141;
  gdl_head = sll_insert_head(p_gdl_tab_st, gdl_head, &test_obj);

  test_obj.th = 1;
  test_obj.tl = 11;
  test_obj.val = 142;
  gdl_head = sll_insert_pos(p_gdl_tab_st, gdl_head, &test_obj, 0);

  test_obj.th = 100;
  test_obj.tl = 100;
  test_obj.val = 100;
  gdl_head = sll_insert_pos(p_gdl_tab_st, gdl_head, &test_obj, 100);

  test_obj.th = 5;
  test_obj.tl = 5;
  test_obj.val = 5;
  gdl_head = sll_insert_pos(p_gdl_tab_st, gdl_head, &test_obj, 4);

  p_gdl_tab_st cur = gdl_head;
  while (cur != NULL)
  {
    printf("%d,%d,%d\n", cur->th, cur->tl, cur->val);
    cur = cur->next;
  }

  printf("?->%p\n", sll_insert_free(p_gdl_tab_st,gdl_head));


  muntrace();

  return 99;
}

