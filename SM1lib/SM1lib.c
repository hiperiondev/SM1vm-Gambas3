/*
 * SM1lib.c
 *
 *  License: GNU GPL V3
 *
 *  Created on: 23 may. 2018
 *  Author: Emiliano Augusto Gonzalez (egonzalez.hiperion@gmail.com)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////
#define UNDER_OVER
#define SWITCH(S) char *_S = S; if (0)
#define CASE(S) } else if (strcmp(_S, S) == 0) {switch(1) { case 1
#define BREAK }
#define DEFAULT } else {switch(1) { case 1
/////////////////////////////////////////////////////////////////////////////////////

#include "SM1.h"

uint8_t sm1_mem_put(uint16_t addr, uint16_t value, vm_t* vm) {
        vm->RAM[addr] = value;
        return RC_OK;
}

uint16_t sm1_mem_get(uint16_t addr, vm_t* vm) {
        return vm->RAM[addr];
}

/////////////////////////////////////////////////////////////////////////////////////

int mem_put(int addr, int value, vm_t* vm){
	return sm1_mem_put((uint16_t) addr, (uint16_t) value, vm);
}

int mem_get(int addr, vm_t* vm){
	return sm1_mem_get((uint16_t) addr, vm);
}
int step(int word, vm_t* vm){
	return sm1_step((uint16_t) word, vm);
}

int read_vm(char var[], vm_t* vm) {
	int result = 0;

	SWITCH(var) {
			CASE("dp"):
				result = vm->dp;
				BREAK
			CASE("rp"):
				result = vm->rp;
				BREAK
			CASE("pc"):
				result = vm->pc;
				BREAK
			CASE("t"):
				result = vm->t;
				BREAK
			CASE("t_ext"):
				result = vm->t_ext;
				BREAK
			CASE("n_ext"):
				result = vm->n_ext;
				BREAK
			CASE("status"):
				result = vm->status;
				BREAK
		}

	return result;
}

int write_vm(char var[], int value, vm_t* vm) {
	SWITCH(var) {
			CASE("dp"):
				vm->dp = value;
				BREAK
			CASE("rp"):
				vm->rp = value;
				BREAK
			CASE("pc"):
				vm->pc = value;
				BREAK
			CASE("t"):
				vm->t = value;
				BREAK
			CASE("t_ext"):
				vm->t_ext = value;
				BREAK
			CASE("n_ext"):
				vm->n_ext = value;
				BREAK;
			CASE("status"):
				vm->status = value;
				BREAK
		}

	return RC_OK;
}

int read_ds(int addr, vm_t *vm ){
	return vm->ds[addr];
}

int write_ds(int addr, int value, vm_t *vm ){
	vm->ds[addr] = value;
	return RC_OK;
}

int read_rs(int addr, vm_t *vm ){
	return vm->rs[addr];
}

int write_rs(int addr, int value, vm_t *vm ){
	vm->rs[addr] = value;
	return RC_OK;
}

vm_t* init(int ramSize, int rsSize, int dsSize) {
        vm_t *vm     = (vm_t *)     malloc(sizeof(vm_t));
        vm->RAM      = (uint16_t *) malloc(sizeof(uint8_t)  * ramSize);
        vm->rs       = (uint16_t *) malloc(sizeof(uint16_t) * rsSize);
        vm->ds       = (uint16_t *) malloc(sizeof(uint16_t) * dsSize);
#ifdef UNDER_OVER
        vm->ds_size  = dsSize;
        vm->rs_size  = rsSize;
        vm->RAM_size = ramSize;
#endif

        return vm;
}
