/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PARSER.h
 * Author: matias
 *
 * Created on 13 de marzo de 2017, 08:33
 */

#ifndef PARSER_H
#define PARSER_H
typedef int (*pCallback) (char *, char*, void *);
int parseCmdLine(int argc, char *argv[], pCallback p, void *userData); 
#define PARSER_RETURN_ERROR -1 //valor que devueleve el parser en caso que suceda un error
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PARSER_H */
