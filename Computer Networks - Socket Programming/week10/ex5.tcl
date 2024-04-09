set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open out.nam w]
$ns namtrace-all $nf

set tr [open out.tr w]
$ns trace-all $tr

proc finish {} {
global ns nf
$ns flush-trace
close $nf
exec nam out.nam &
exit 0
}

set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

$ns duplex-link $n1 $n2 2Mb 20ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail

set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n1 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 2

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

set tcp2 [new Agent/TCP]
$tcp2 set class_ 1
$ns attach-agent $n3 $tcp2

set sink2 [new Agent/TCPSink]
$ns attach-agent $n4 $sink2
$ns connect $tcp2 $sink2
$tcp2 set fid_ 2

set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ftp2 set type_ FTP

$ns at 0.1 "$ftp start"
$ns at 0.2 "$ftp2 start"
$ns at 3.0 "$ftp stop"
$ns at 4.0 "$ftp2 stop"
$ns at 5.0 "finish"

$ns run
