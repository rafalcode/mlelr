/* dataset.h */

/*

Copyright (C) 2015 Scott A. Czepiel

    This file is part of mlelr.

    mlelr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    mlelr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with mlelr.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef DATASET_H__
#define DATASET_H__

extern const double SYSMIS;

/***
    dataset

    A basic abstraction for storing and accessing data and metadata.
***/
typedef struct /* dataset_t, the dataset type */
{
    char    *handle;        /* a short label for this dataset */
    int      n;             /* number of observations */
    int      size;          /* amount of space allocated for values */
    int      nvars;         /* number of variables */
    char   **varnames;      /* array of variable names */
    double  *values;        /* array of contiguous space to store all data */
    double **obs;           /* matrix of pointers to access each obs[i][j] */
    int      weight;        /* index of the weight variable, or -1 if none */
} dataset_t;

/*** dataspace

    This global variable will hold an array of pointers to all currently
    available datasets.
***/
struct dataspace
{
    int      n;              /* number of datasets */
    int      size;           /* space allocated to store pointers to datasets */
    dataset_t *datasets;       /* array of datasets */
};
extern struct dataspace dataspace; //defines global variable for it.


/* forward declarations for publically available functions defined in dataset.c */

extern void init_dataspace (void);
extern int import_dataset (char *handle, char *filename, char delim);
extern dataset_t *add_dataset (char *handle, int nvars, char **varnames, int is_public);
extern void add_observation (dataset_t *ds, double *obs);
extern void print_dataset (dataset_t *ds, int n, int header);
extern dataset_t *find_dataset (char *handle);
extern int find_varname (dataset_t *ds, char *varname);
extern int set_weight_variable (dataset_t *ds, int var);
extern int find_observation(dataset_t *ds, double *obs, int n_vars);
extern void sort_dataset(dataset_t *ds, int n_cols);

#endif
