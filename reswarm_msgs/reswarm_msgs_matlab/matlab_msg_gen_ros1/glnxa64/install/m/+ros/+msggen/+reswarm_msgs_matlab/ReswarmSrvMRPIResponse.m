
classdef ReswarmSrvMRPIResponse < ros.Message
    %ReswarmSrvMRPIResponse MATLAB implementation of reswarm_msgs_matlab/ReswarmSrvMRPIResponse
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'reswarm_msgs_matlab/ReswarmSrvMRPIResponse' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '8a47b189a3d7851bf5fc06c078453f12' % The MD5 Checksum of the message definition
        PropertyList = { 'K' 'Au' 'Bu' 'AZ' 'BZ' } % List of non-constant message properties
        ROSPropertyList = { 'K' 'Au' 'bu' 'AZ' 'bZ' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Float64MultiArray' ...
            'ros.msggen.std_msgs.Float64MultiArray' ...
            'ros.msggen.std_msgs.Float64MultiArray' ...
            'ros.msggen.std_msgs.Float64MultiArray' ...
            'ros.msggen.std_msgs.Float64MultiArray' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        K
        Au
        Bu
        AZ
        BZ
    end
    methods
        function set.K(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Float64MultiArray'};
            validateattributes(val, validClasses, validAttributes, 'ReswarmSrvMRPIResponse', 'K')
            obj.K = val;
        end
        function set.Au(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Float64MultiArray'};
            validateattributes(val, validClasses, validAttributes, 'ReswarmSrvMRPIResponse', 'Au')
            obj.Au = val;
        end
        function set.Bu(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Float64MultiArray'};
            validateattributes(val, validClasses, validAttributes, 'ReswarmSrvMRPIResponse', 'Bu')
            obj.Bu = val;
        end
        function set.AZ(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Float64MultiArray'};
            validateattributes(val, validClasses, validAttributes, 'ReswarmSrvMRPIResponse', 'AZ')
            obj.AZ = val;
        end
        function set.BZ(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Float64MultiArray'};
            validateattributes(val, validClasses, validAttributes, 'ReswarmSrvMRPIResponse', 'BZ')
            obj.BZ = val;
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.reswarm_msgs_matlab.ReswarmSrvMRPIResponse.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.reswarm_msgs_matlab.ReswarmSrvMRPIResponse(strObj);
        end
    end
end