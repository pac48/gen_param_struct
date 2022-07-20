// this is auto-generated code 

#pragma once

#include <rclcpp/node.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <vector>
#include <string>
#include <gen_param_struct/validators.hpp>


namespace admittance_controller_parameters {

  class Result {
  public:
    template<typename ... Args>
    Result(const std::string &format, Args ... args) {
      int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
      if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
      auto size = static_cast<size_t>( size_s );
      std::unique_ptr<char[]> buf(new char[size]);
      std::snprintf(buf.get(), size, format.c_str(), args ...);
      msg_ = std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
      success_ = false;
    }

    Result() {
      success_ = true;
    }

    bool success() {
      return success_;
    }

    std::string error_msg() {
      return msg_;
    }

  private:
    std::string msg_;
    bool success_;
  };

  auto OK = Result();
  using ERROR = Result;

  Result validate_string_array_len(const rclcpp::Parameter &parameter, size_t size) {
    const auto &string_array = parameter.as_string_array();
    if (string_array.size() != size) {
      return ERROR(
          "The length of the parameter was incorrect. Expected size is %d, actual size is %d",
          size, string_array.size());
    }
    return OK;
  }

  Result validate_double_array_len(const rclcpp::Parameter &parameter, size_t size) {
    const auto &double_array = parameter.as_double_array();
    if (double_array.size() != size) {
      return ERROR(
          "The length of the parameter was incorrect. Expected size is %d, actual size is %d",
          size, double_array.size());
    }
    return OK;
  }

  Result validate_bool_array_len(const rclcpp::Parameter &parameter, size_t size) {
    const auto &bool_array = parameter.as_bool_array();
    if (bool_array.size() != size) {
      return ERROR(
          "The length of the parameter was incorrect. Expected size is %d, actual size is %d",
          size, bool_array.size());
    }
    return OK;
  }

  Result validate_double_array_bounds(const rclcpp::Parameter &parameter, double lower_bound, double upper_bound) {
    const auto &double_array = parameter.as_double_array();
    for (auto val: double_array) {
      if (val < lower_bound || val > upper_bound) {
        return ERROR(
            "The parameter value (%f) was outside the allowed bounds [(%f), (%f)]",
            val, lower_bound, upper_bound);
      }
    }
    return OK;
  }

  struct Params {
    std::vector<std::string> joints_;
    std::vector<std::string> command_interfaces_;
    std::vector<std::string> state_interfaces_;
    std::vector<std::string> chainable_command_interfaces_;
    struct kinematics {
      std::string plugin_name_;
      std::string plugin_package_;
      std::string base_;
      std::string tip_;
      double alpha_ = 0.0005;
      std::string group_name_;
    } kinematics_;
    struct ft_sensor {
      std::string name_;
      struct frame {
        std::string id_;
        bool external_;
      } frame_;
      double filter_coefficient_ = 0.005;
    } ft_sensor_;
    struct control {
      struct frame {
        std::string id_;
        bool external_;
      } frame_;
    } control_;
    struct fixed_world_frame {
      struct frame {
        std::string id_;
        bool external_;
      } frame_;
    } fixed_world_frame_;
    struct gravity_compensation {
      struct frame {
        std::string id_;
        bool external_;
      } frame_;
      struct CoG {
        std::vector<double> pos_;
        double force_ = std::numeric_limits<double>::quiet_NaN();
      } CoG_;
    } gravity_compensation_;
    struct admittance {
      std::vector<bool> selected_axes_;
      std::vector<double> mass_;
      std::vector<double> damping_ratio_;
      std::vector<double> stiffness_;
    } admittance_;
    bool enable_parameter_update_without_reactivation_ = true;
    bool use_feedforward_commanded_input_ = true;

    // for detecting if the parameter struct has been updated
    rclcpp::Time __stamp;
  };

  class ParamListener {
  public:
    // throws rclcpp::exceptions::InvalidParameterValueException on initialization if invalid parameter are loaded
    ParamListener(rclcpp::Node::SharedPtr node)
        : ParamListener(node->get_node_parameters_interface()) {}

    ParamListener(rclcpp_lifecycle::LifecycleNode::SharedPtr node)
        : ParamListener(node->get_node_parameters_interface()) {}

    ParamListener(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> &parameters_interface) {
      declare_params(parameters_interface);
      auto update_param_cb = [this](const std::vector<rclcpp::Parameter> &parameters) {
        return this->update(parameters);
      };
      handle_ = parameters_interface->add_on_set_parameters_callback(update_param_cb);
      clock_ = rclcpp::Clock();
    }

    Params get_params() const {
      return params_;
    }

    bool is_invalid(Params const &other) const {
      return params_.__stamp != other.__stamp;
    }

    rcl_interfaces::msg::SetParametersResult update(const std::vector<rclcpp::Parameter> &parameters) {
      rcl_interfaces::msg::SetParametersResult result;
      result.successful = false;
      gen_param_struct_validators::Result validation_result;

      result.reason = "success";
      for (const auto &param: parameters) {
        if (param.get_name() == "joints") {
          params_.joints_ = param.as_string_array();
          result.successful = true;
        }
        if (param.get_name() == "command_interfaces") {
          params_.command_interfaces_ = param.as_string_array();
          result.successful = true;
        }
        if (param.get_name() == "state_interfaces") {
          params_.state_interfaces_ = param.as_string_array();
          result.successful = true;
        }
        if (param.get_name() == "chainable_command_interfaces") {
          params_.chainable_command_interfaces_ = param.as_string_array();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.plugin_name") {
          params_.kinematics_.plugin_name_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.plugin_package") {
          params_.kinematics_.plugin_package_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.base") {
          params_.kinematics_.base_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.tip") {
          params_.kinematics_.tip_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.alpha") {
          params_.kinematics_.alpha_ = param.as_double();
          result.successful = true;
        }
        if (param.get_name() == "kinematics.group_name") {
          params_.kinematics_.group_name_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "ft_sensor.name") {
          params_.ft_sensor_.name_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "ft_sensor.frame.id") {
          params_.ft_sensor_.frame_.id_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "ft_sensor.frame.external") {
          params_.ft_sensor_.frame_.external_ = param.as_bool();
          result.successful = true;
        }
        if (param.get_name() == "ft_sensor.filter_coefficient") {
          params_.ft_sensor_.filter_coefficient_ = param.as_double();
          result.successful = true;
        }
        if (param.get_name() == "control.frame.id") {
          params_.control_.frame_.id_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "control.frame.external") {
          params_.control_.frame_.external_ = param.as_bool();
          result.successful = true;
        }
        if (param.get_name() == "fixed_world_frame.frame.id") {
          params_.fixed_world_frame_.frame_.id_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "fixed_world_frame.frame.external") {
          params_.fixed_world_frame_.frame_.external_ = param.as_bool();
          result.successful = true;
        }
        if (param.get_name() == "gravity_compensation.frame.id") {
          params_.gravity_compensation_.frame_.id_ = param.as_string();
          result.successful = true;
        }
        if (param.get_name() == "gravity_compensation.frame.external") {
          params_.gravity_compensation_.frame_.external_ = param.as_bool();
          result.successful = true;
        }
        if (param.get_name() == "gravity_compensation.CoG.pos") {
          validation_result = gen_param_struct_validators::validate_double_array_len(param, 3);
          if (validation_result.success()) {
            params_.gravity_compensation_.CoG_.pos_ = param.as_double_array();
            result.successful = true;
          } else {
            result.reason = validation_result.error_msg();
            result.successful = false;
          }
        }
        if (param.get_name() == "gravity_compensation.CoG.force") {
          params_.gravity_compensation_.CoG_.force_ = param.as_double();
          result.successful = true;
        }
        if (param.get_name() == "admittance.selected_axes") {
          validation_result = gen_param_struct_validators::validate_bool_array_len(param, 6);
          if (validation_result.success()) {
            params_.admittance_.selected_axes_ = param.as_bool_array();
            result.successful = true;
          } else {
            result.reason = validation_result.error_msg();
            result.successful = false;
          }
        }
        if (param.get_name() == "admittance.mass") {
          validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.0001, 1000000.0);
          if (validation_result.success()) {
            validation_result = gen_param_struct_validators::validate_double_array_len(param, 6);
            if (validation_result.success()) {
              params_.admittance_.mass_ = param.as_double_array();
              result.successful = true;
            } else {
              result.reason = validation_result.error_msg();
              result.successful = false;
            }
          } else {
            result.reason = validation_result.error_msg();
            result.successful = false;
          }
        }
        if (param.get_name() == "admittance.damping_ratio") {
          validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.1, 10.0);
          if (validation_result.success()) {
            validation_result = gen_param_struct_validators::validate_double_array_len(param, 6);
            if (validation_result.success()) {
              params_.admittance_.damping_ratio_ = param.as_double_array();
              result.successful = true;
            } else {
              result.reason = validation_result.error_msg();
              result.successful = false;
            }
          } else {
            result.reason = validation_result.error_msg();
            result.successful = false;
          }
        }
        if (param.get_name() == "admittance.stiffness") {
          validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.0001, 100000.0);
          if (validation_result.success()) {
            params_.admittance_.stiffness_ = param.as_double_array();
            result.successful = true;
          } else {
            result.reason = validation_result.error_msg();
            result.successful = false;
          }
        }
        if (param.get_name() == "enable_parameter_update_without_reactivation") {
          params_.enable_parameter_update_without_reactivation_ = param.as_bool();
          result.successful = true;
        }
        if (param.get_name() == "use_feedforward_commanded_input") {
          params_.use_feedforward_commanded_input_ = param.as_bool();
          result.successful = true;
        }

      }
      if (result.successful) {
        params_.__stamp = clock_.now();
      }
      return result;
    }

    void declare_params(const std::shared_ptr<rclcpp::node_interfaces::NodeParametersInterface> &parameters_interface) {
      // declare all parameters and give default values to non-required ones

      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies which joints will be used by the controller";
        descriptor.read_only = true;
        if (!parameters_interface->has_parameter("joints")) {
          auto p_joints = rclcpp::ParameterType::PARAMETER_STRING_ARRAY;
          parameters_interface->declare_parameter("joints", p_joints, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies which command interfaces to claim";
        descriptor.read_only = true;
        if (!parameters_interface->has_parameter("command_interfaces")) {
          auto p_command_interfaces = rclcpp::ParameterType::PARAMETER_STRING_ARRAY;
          parameters_interface->declare_parameter("command_interfaces", p_command_interfaces, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies which state interfaces to claim";
        descriptor.read_only = true;
        if (!parameters_interface->has_parameter("state_interfaces")) {
          auto p_state_interfaces = rclcpp::ParameterType::PARAMETER_STRING_ARRAY;
          parameters_interface->declare_parameter("state_interfaces", p_state_interfaces, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies which chainable interfaces to claim";
        descriptor.read_only = true;
        if (!parameters_interface->has_parameter("chainable_command_interfaces")) {
          auto p_chainable_command_interfaces = rclcpp::ParameterType::PARAMETER_STRING_ARRAY;
          parameters_interface->declare_parameter("chainable_command_interfaces", p_chainable_command_interfaces,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies which kinematics plugin to load";
        if (!parameters_interface->has_parameter("kinematics.plugin_name")) {
          auto p_kinematics_plugin_name = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("kinematics.plugin_name", p_kinematics_plugin_name, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the package to load the kinematics plugin from";
        if (!parameters_interface->has_parameter("kinematics.plugin_package")) {
          auto p_kinematics_plugin_package = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("kinematics.plugin_package", p_kinematics_plugin_package, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the base link of the robot description used by the kinematics plugin";
        if (!parameters_interface->has_parameter("kinematics.base")) {
          auto p_kinematics_base = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("kinematics.base", p_kinematics_base, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the end effector link of the robot description used by the kinematics plugin";
        if (!parameters_interface->has_parameter("kinematics.tip")) {
          auto p_kinematics_tip = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("kinematics.tip", p_kinematics_tip, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the damping coefficient for the Jacobian pseudo inverse";
        if (!parameters_interface->has_parameter("kinematics.alpha")) {
          auto p_kinematics_alpha = rclcpp::ParameterValue(params_.kinematics_.alpha_);
          parameters_interface->declare_parameter("kinematics.alpha", p_kinematics_alpha, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the group name for planning with Moveit";
        if (!parameters_interface->has_parameter("kinematics.group_name")) {
          auto p_kinematics_group_name = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("kinematics.group_name", p_kinematics_group_name, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "name of the force torque sensor in the robot description";
        if (!parameters_interface->has_parameter("ft_sensor.name")) {
          auto p_ft_sensor_name = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("ft_sensor.name", p_ft_sensor_name, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "frame of the force torque sensor";
        if (!parameters_interface->has_parameter("ft_sensor.frame.id")) {
          auto p_ft_sensor_frame_id = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("ft_sensor.frame.id", p_ft_sensor_frame_id, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies if the force torque sensor is contained in the kinematics chain from the base to the tip";
        if (!parameters_interface->has_parameter("ft_sensor.frame.external")) {
          auto p_ft_sensor_frame_external = rclcpp::ParameterType::PARAMETER_BOOL;
          parameters_interface->declare_parameter("ft_sensor.frame.external", p_ft_sensor_frame_external, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies the coefficient for the sensor's exponential filter";
        if (!parameters_interface->has_parameter("ft_sensor.filter_coefficient")) {
          auto p_ft_sensor_filter_coefficient = rclcpp::ParameterValue(params_.ft_sensor_.filter_coefficient_);
          parameters_interface->declare_parameter("ft_sensor.filter_coefficient", p_ft_sensor_filter_coefficient,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "control frame used for admittance control";
        if (!parameters_interface->has_parameter("control.frame.id")) {
          auto p_control_frame_id = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("control.frame.id", p_control_frame_id, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies if the control frame is contained in the kinematics chain from the base to the tip";
        if (!parameters_interface->has_parameter("control.frame.external")) {
          auto p_control_frame_external = rclcpp::ParameterType::PARAMETER_BOOL;
          parameters_interface->declare_parameter("control.frame.external", p_control_frame_external, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "world frame, gravity points down (neg. Z) in this frame";
        if (!parameters_interface->has_parameter("fixed_world_frame.frame.id")) {
          auto p_fixed_world_frame_frame_id = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("fixed_world_frame.frame.id", p_fixed_world_frame_frame_id,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies if the world frame is contained in the kinematics chain from the base to the tip";
        if (!parameters_interface->has_parameter("fixed_world_frame.frame.external")) {
          auto p_fixed_world_frame_frame_external = rclcpp::ParameterType::PARAMETER_BOOL;
          parameters_interface->declare_parameter("fixed_world_frame.frame.external",
                                                  p_fixed_world_frame_frame_external, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "frame which center of gravity (CoG) is defined in";
        if (!parameters_interface->has_parameter("gravity_compensation.frame.id")) {
          auto p_gravity_compensation_frame_id = rclcpp::ParameterType::PARAMETER_STRING;
          parameters_interface->declare_parameter("gravity_compensation.frame.id", p_gravity_compensation_frame_id,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies if the center of gravity frame is contained in the kinematics chain from the base to the tip";
        if (!parameters_interface->has_parameter("gravity_compensation.frame.external")) {
          auto p_gravity_compensation_frame_external = rclcpp::ParameterType::PARAMETER_BOOL;
          parameters_interface->declare_parameter("gravity_compensation.frame.external",
                                                  p_gravity_compensation_frame_external, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "position of the center of gravity (CoG) in its frame";
        if (!parameters_interface->has_parameter("gravity_compensation.CoG.pos")) {
          auto p_gravity_compensation_CoG_pos = rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY;
          parameters_interface->declare_parameter("gravity_compensation.CoG.pos", p_gravity_compensation_CoG_pos,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "weight of the end effector, e.g mass * 9.81";
        if (!parameters_interface->has_parameter("gravity_compensation.CoG.force")) {
          auto p_gravity_compensation_CoG_force = rclcpp::ParameterValue(params_.gravity_compensation_.CoG_.force_);
          parameters_interface->declare_parameter("gravity_compensation.CoG.force", p_gravity_compensation_CoG_force,
                                                  descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies if the axes x, y, z, rx, ry, and rz are enabled";
        if (!parameters_interface->has_parameter("admittance.selected_axes")) {
          auto p_admittance_selected_axes = rclcpp::ParameterType::PARAMETER_BOOL_ARRAY;
          parameters_interface->declare_parameter("admittance.selected_axes", p_admittance_selected_axes, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies mass values for x, y, z, rx, ry, and rz used in the admittance calculation";
        rcl_interfaces::msg::FloatingPointRange range;
        range.from_value = 0.0001;
        range.to_value = 1000000.0;
        descriptor.floating_point_range.push_back(range);
        if (!parameters_interface->has_parameter("admittance.mass")) {
          auto p_admittance_mass = rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY;
          parameters_interface->declare_parameter("admittance.mass", p_admittance_mass, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies damping ratio values for x, y, z, rx, ry, and rz used in the admittance calculation. The values are calculated as damping can be used instead: zeta = D / (2 * sqrt( M * S ))";
        rcl_interfaces::msg::FloatingPointRange range;
        range.from_value = 0.1;
        range.to_value = 10.0;
        descriptor.floating_point_range.push_back(range);
        if (!parameters_interface->has_parameter("admittance.damping_ratio")) {
          auto p_admittance_damping_ratio = rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY;
          parameters_interface->declare_parameter("admittance.damping_ratio", p_admittance_damping_ratio, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "specifies stiffness values for x, y, z, rx, ry, and rz used in the admittance calculation";
        rcl_interfaces::msg::FloatingPointRange range;
        range.from_value = 0.0001;
        range.to_value = 100000.0;
        descriptor.floating_point_range.push_back(range);
        if (!parameters_interface->has_parameter("admittance.stiffness")) {
          auto p_admittance_stiffness = rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY;
          parameters_interface->declare_parameter("admittance.stiffness", p_admittance_stiffness, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "if enabled, read_only parameters will be dynamically updated in the control loop";
        if (!parameters_interface->has_parameter("enable_parameter_update_without_reactivation")) {
          auto p_enable_parameter_update_without_reactivation = rclcpp::ParameterValue(
              params_.enable_parameter_update_without_reactivation_);
          parameters_interface->declare_parameter("enable_parameter_update_without_reactivation",
                                                  p_enable_parameter_update_without_reactivation, descriptor);
        }
      }
      {
        rcl_interfaces::msg::ParameterDescriptor descriptor;
        descriptor.description = "if enabled, the velocity commanded to the admittance controller is added to its calculated admittance velocity";
        if (!parameters_interface->has_parameter("use_feedforward_commanded_input")) {
          auto p_use_feedforward_commanded_input = rclcpp::ParameterValue(params_.use_feedforward_commanded_input_);
          parameters_interface->declare_parameter("use_feedforward_commanded_input", p_use_feedforward_commanded_input,
                                                  descriptor);
        }
      }

      // get parameters and fill struct fields
      rclcpp::Parameter param;
      gen_param_struct_validators::Result validation_result;

      param = parameters_interface->get_parameter("joints");
      params_.joints_ = param.as_string_array();
      param = parameters_interface->get_parameter("command_interfaces");
      params_.command_interfaces_ = param.as_string_array();
      param = parameters_interface->get_parameter("state_interfaces");
      params_.state_interfaces_ = param.as_string_array();
      param = parameters_interface->get_parameter("chainable_command_interfaces");
      params_.chainable_command_interfaces_ = param.as_string_array();
      param = parameters_interface->get_parameter("kinematics.plugin_name");
      params_.kinematics_.plugin_name_ = param.as_string();
      param = parameters_interface->get_parameter("kinematics.plugin_package");
      params_.kinematics_.plugin_package_ = param.as_string();
      param = parameters_interface->get_parameter("kinematics.base");
      params_.kinematics_.base_ = param.as_string();
      param = parameters_interface->get_parameter("kinematics.tip");
      params_.kinematics_.tip_ = param.as_string();
      param = parameters_interface->get_parameter("kinematics.alpha");
      params_.kinematics_.alpha_ = param.as_double();
      param = parameters_interface->get_parameter("kinematics.group_name");
      params_.kinematics_.group_name_ = param.as_string();
      param = parameters_interface->get_parameter("ft_sensor.name");
      params_.ft_sensor_.name_ = param.as_string();
      param = parameters_interface->get_parameter("ft_sensor.frame.id");
      params_.ft_sensor_.frame_.id_ = param.as_string();
      param = parameters_interface->get_parameter("ft_sensor.frame.external");
      params_.ft_sensor_.frame_.external_ = param.as_bool();
      param = parameters_interface->get_parameter("ft_sensor.filter_coefficient");
      params_.ft_sensor_.filter_coefficient_ = param.as_double();
      param = parameters_interface->get_parameter("control.frame.id");
      params_.control_.frame_.id_ = param.as_string();
      param = parameters_interface->get_parameter("control.frame.external");
      params_.control_.frame_.external_ = param.as_bool();
      param = parameters_interface->get_parameter("fixed_world_frame.frame.id");
      params_.fixed_world_frame_.frame_.id_ = param.as_string();
      param = parameters_interface->get_parameter("fixed_world_frame.frame.external");
      params_.fixed_world_frame_.frame_.external_ = param.as_bool();
      param = parameters_interface->get_parameter("gravity_compensation.frame.id");
      params_.gravity_compensation_.frame_.id_ = param.as_string();
      param = parameters_interface->get_parameter("gravity_compensation.frame.external");
      params_.gravity_compensation_.frame_.external_ = param.as_bool();
      param = parameters_interface->get_parameter("gravity_compensation.CoG.pos");
      if (validate_double_array_len(param, 3).success()
          && validate_double_array_len(param, 3).success()) {
        params_.gravity_compensation_.CoG_.pos_ = param.as_double_array();
      } else {
        throw rclcpp::exceptions::InvalidParameterValueException(
            "Invalid value set during initialization for parameter gravity_compensation.CoG.pos: " +
            validation_result.error_msg());
      }
      param = parameters_interface->get_parameter("gravity_compensation.CoG.force");
      params_.gravity_compensation_.CoG_.force_ = param.as_double();
      param = parameters_interface->get_parameter("admittance.selected_axes");
      validation_result = gen_param_struct_validators::validate_bool_array_len(param, 6);
      if (validation_result.success()) {
        params_.admittance_.selected_axes_ = param.as_bool_array();
      } else {
        throw rclcpp::exceptions::InvalidParameterValueException(
            "Invalid value set during initialization for parameter admittance.selected_axes: " +
            validation_result.error_msg());
      }
      param = parameters_interface->get_parameter("admittance.mass");
      validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.0001, 1000000.0);
      if (validation_result.success()) {
        validation_result = gen_param_struct_validators::validate_double_array_len(param, 6);
        if (validation_result.success()) {
          params_.admittance_.mass_ = param.as_double_array();
        } else {
          throw rclcpp::exceptions::InvalidParameterValueException(
              "Invalid value set during initialization for parameter admittance.mass: " +
              validation_result.error_msg());
        }
      } else {
        throw rclcpp::exceptions::InvalidParameterValueException(
            "Invalid value set during initialization for parameter admittance.mass: " + validation_result.error_msg());
      }
      param = parameters_interface->get_parameter("admittance.damping_ratio");
      validation_result = gen_param_struct_validators::validate_double_array_custom_func(param, 20.3, 5.0);
      if (validation_result.success()) {
        validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.1, 10.0);
        if (validation_result.success()) {
          validation_result = gen_param_struct_validators::validate_double_array_len(param, 6);
          if (validation_result.success()) {
            params_.admittance_.damping_ratio_ = param.as_double_array();
          } else {
            throw rclcpp::exceptions::InvalidParameterValueException(
                "Invalid value set during initialization for parameter admittance.damping_ratio: " +
                validation_result.error_msg());
          }
        } else {
          throw rclcpp::exceptions::InvalidParameterValueException(
              "Invalid value set during initialization for parameter admittance.damping_ratio: " +
              validation_result.error_msg());
        }
      } else {
        throw rclcpp::exceptions::InvalidParameterValueException(
            "Invalid value set during initialization for parameter admittance.damping_ratio: " +
            validation_result.error_msg());
      }
      param = parameters_interface->get_parameter("admittance.stiffness");
      validation_result = gen_param_struct_validators::validate_double_array_bounds(param, 0.0001, 100000.0);
      if (validation_result.success()) {
        params_.admittance_.stiffness_ = param.as_double_array();
      } else {
        throw rclcpp::exceptions::InvalidParameterValueException(
            "Invalid value set during initialization for parameter admittance.stiffness: " +
            validation_result.error_msg());
      }
      param = parameters_interface->get_parameter("enable_parameter_update_without_reactivation");
      params_.enable_parameter_update_without_reactivation_ = param.as_bool();
      param = parameters_interface->get_parameter("use_feedforward_commanded_input");
      params_.use_feedforward_commanded_input_ = param.as_bool();

      params_.__stamp = clock_.now();
    }

  private:
    std::mutex mutex_;
    Params params_;
    rclcpp::Clock clock_;
    std::shared_ptr<rclcpp::node_interfaces::OnSetParametersCallbackHandle> handle_;
  };

} // namespace admittance_controller_parameters
