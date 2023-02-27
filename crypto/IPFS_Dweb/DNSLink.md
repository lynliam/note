# DNSLink

DNSLink uses DNS TXT records to map a DNS name. Since DNSLink uses DNS records , you can assign names, paths, and sub-domains that are easy to type, read, and remember.

```markdown
/ipns/example.org
```



### Punlish content path

Publish the mapping as DNS `TXT` record using your hostname prefixed with `_dnslink`.This not only makes DNSLink lookup more efficient by only returning relevant `TXT` records but enables you to improve the security of an automated setup  or delegate control over your DNSLink records to a third party without  giving away complete control over the original DNS zone.

```json
dig +noall +answer TXT \_dnslink.docs.ipfs.tech
> \_dnslink.docs.ipfs.tech. 30 IN TXT "dnslink=/ipfs/bafybeieenxnjdjm7vbr5zdwemaun4sw4iy7h4imlvvl433q6gzjg6awdpq"
```

### Resolve DNSLink name

When an IPFS client or node attempts to resolve an address, it looks for a `TXT` record that is prefixed with `dnslink=`. The rest can be an `/ipfs/` link (as in the example below), or `/ipns/`, or even a link to another DNSLink.

```json
dnslink=/ipfs/<CID for your content here>
```



