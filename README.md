# The Dark Side of Unikernels for Machine Learning Applications

This repo is home to the supporting materials for the paper I wrote for my undergraduate research under advisor Aniruddha Gokhale while at Vanderbilt University in Spring 2020. From the abstract:

> This paper analyzes the shortcomings of unikernels as a method of deployment for machine learning inferencing applications as well as provides insights and analysis on future work in this space. The findings of this paper advocate for a tool to enable management of dependent libraries in a unikernel to enable a more ergonomic build process as well as take advantage of the inherent security and perfomance benefits of unikernels.

The full paper can be found [in this repo](./Leon-the-dark-side-of-unikernels.pdf).

The examples are split into two main categories: those used to demo the `unik` tool and those used to demo the `ops` tool from Nanos VMs. Each folder contains numerous examples demoing basic use and/or shortcomings of the unikernel used to run the example. Each example includes the information required to run the example.

The software versions used in the writing of this paper:

| Software Component | Version        |
| ------------------ | -------------- |
| Ops                | 0.1.9          |
| Unik               | Commit a58d3e8 |
| Tensorflow         | v1.15.3        |

The [memory-deduplication.md](./memory-deduplication.md) contains supplemental materials that were interesting enough to leave in this repo.
