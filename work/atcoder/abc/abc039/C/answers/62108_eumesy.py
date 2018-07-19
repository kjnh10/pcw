#! /usr/bin/env python3
# -*- coding: utf-8 -*-

keyboard = 'WBWBWWBWBWBW' * 3
ans = ['Do','','Re','','Mi','Fa','','So','','La','','Si']
S = input()
print(ans[keyboard.find(S)])
