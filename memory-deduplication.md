# Memory Deduplication

This page addresses one of the core issues with unikernels when compared to a
solution like NixOS or Docker: Memory duplication. At first glance, it seems as
though Unikernels require more space because they must re-load the entire OS for
every running version of the unik. This is actually not so bad on certain
Hypervisors; however, because some of them use transparent page sharing and/or
same-page merging and Copy-on-Write techniques to ensure that there is only one
copy of the OS image in ram on these machines running under Xen, VMWare, or KVM.

## Security

[Memory Deduplication as a Threat to the Guest OS](https://www.diva-portal.org/smash/get/diva2:1060434/FULLTEXT01.pdf)

[Fine grain Cross-VM Attacks on Xen and VMware are possible!](https://eprint.iacr.org/2014/248.pdf)

These papers would both tend to indicate that same-page sharing is dangerous for
security reasons, but they do not consider the possibility that the rest of the
applications on the system are single-process VMs. In these papers, the biggest
risk is detecting which programs are running on other VMs on the system. This is
a big deal for large cloud providers running full interactive systems on other
VMs on the same hypervisor (e.g. Amazon EC2), but is perhaps not as important
for a hypervisor only running unikernels because no information about running
programs can be leaked, only that there _is_ another unikernel, furthermore, if
the unikernel is running the same thing then it is even more of a non-starter.

## Details on how it is accomplished

[KVM Docs on Samepage Merging](https://www.linux-kvm.org/page/KSM#Kernel_Samepage_Merging)

[VMDedup: Memory De-duplication in Hypervisor](https://tcipg.org/sites/default/files/papers/2014_Q1_Forensics1.pdf)

[Efficient Memory Sharing in the Xen Virtual Machine Monitor](http://mejlholm.org/uni/pdfs/dat5.pdf)


